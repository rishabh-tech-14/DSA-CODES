#include<iostream>
#include<vector>
#include<climits>
using namespace std;

// BRUTE-FORCE APPROACH
int searchMin1(vector<int> v){
    int n = v.size();
    int min = INT_MAX;
    
    for(int i = 0 ; i<n ; i++){
        if(v[i]<min){
            min=v[i];
        }
    }

    return min;
}

// OPTIMAL APPROACH
int searchMin2(vector<int> v){
    int n = v.size();
    int low=0 , high=n-1;
    int ans = INT_MAX;

    while(low<=high){
        int mid = (low+high)/2;

        if(v[low]<=v[high]){
            ans = min(ans,v[low]);
            break;
        }

        if(v[low]<=v[mid]){
            ans = min(ans,v[low]);
            low=mid+1;
        }
        else{
            ans=min(ans,v[mid]);
            high=mid-1;
        }
    }

    return ans;
}

int main(){
    vector<int> v = {4, 5, 6, 7, 0, 1, 2};

    cout<<searchMin2(v);

    return 0;
}