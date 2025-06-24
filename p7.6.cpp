#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
using namespace std;

// BRUTE-FORCE APPROACH
int findDays1(vector<int> weights , int cap){
    int n = weights.size();
    int load = 0 ;
    int day = 1;

    for(int i = 0 ; i<n ; i++){
        if(load+weights[i]>cap){
            day +=1 ;
            load = weights[i];
        }
        else load += weights[i];
    }

    return day;
}
int leastweightcap1(vector<int> weights , int d){
    int n = weights.size();
    int maxi = *max_element(weights.begin() , weights.end());
    int sum = accumulate(weights.begin(), weights.end(),0);

    for(int i = maxi ; i<=sum ; i++){
        if (findDays1(weights,i)<=d){
            return i;
        }
    }

    return -1;
}

// OPTIMAL APPROACH
int findDays2(vector<int> weights , int cap){
    int n = weights.size();
    int load = 0; 
    int days = 1;

    for(int i = 0 ; i<n ; i++){
        if(load+weights[i]>cap){
            load = weights[i];
            days += 1;
        }
        else load += weights[i];
    }

    return days;
}

int leastweightcap2(vector<int> weights , int d){
    int n = weights.size();

    int low = *max_element(weights.begin(),weights.end());
    int high = accumulate(weights.begin(),weights.end(),0);

    while(low<=high){
        int mid = (low+high)/2;
        int cap = findDays2(weights,mid);

        if(cap<=d) high=mid-1;

        else low=mid+1;
    }

    return low;


}

int main(){
    vector<int> weight = {5, 4, 5, 2, 3, 4, 5, 6};
    int days = 5;
    
    int ans = leastweightcap2(weight,days);

    cout<<ans;


    return 0;
}


