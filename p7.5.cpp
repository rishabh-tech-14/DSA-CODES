#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

// BRUTE-FORCE APPROACH
int smallestDivisor1(vector<int> v , int limit){
    int n = v.size();
    int maxi = *max_element(v.begin(),v.end());

    for(int d = 1 ; d<=maxi ; d++){
        int sum=0;
        for(int i = 0 ; i<n ; i++){
            sum += ceil(double(v[i])/d);
        }
        if(sum<=limit) return d;
    }

    return -1;
    
}

// OPTIMAL APPROACH
int findDiv2(vector<int> v,int div){
    int n = v.size();
    int sum=0;

    for(int i = 0 ; i<n ; i++){
        sum += ceil(double(v[i])/div);
    }

    return sum;

}
int smallestDivisor2(vector<int> v , int limit){
    int n = v.size();
    int low = 1 , high = *max_element(v.begin(),v.end());

    while(low<=high){
        int mid = (low+high)/2;

        if(findDiv2(v,mid)<=limit){
            high=mid-1;
        }

        else low=mid+1;
    }

    return low;
}

int main(){
    vector<int> v = {1, 2, 3, 4, 5};
    int limit = 8;

    cout<<smallestDivisor2(v,limit);

    return 0;
}