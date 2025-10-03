#include<iostream>
#include<vector>
using namespace std;

// BRUTE-FORCE APPROACH
int singleEle1(vector<int> &v){
    int n = v.size();

    for(int i = 0 ; i<n ; i++){
        if(i==0){
            if(v[i] != v[i+1]) return v[i];
        }
        else if(i==n-1){
            if(v[i] != v[i-1]) return v[i];
        }
        else{
            if(v[i] != v[i+1] && v[i] != v[i-1]){
                return v[i];
            }
        }
    }

    return -1;
}

// BETTER APPROACH
int singleEle2(vector<int> v){
    int n = v.size();
    int ans=0;

    for(int i = 0 ; i<n ; i++){
        ans = ans^v[i];
    }

    return ans;
}

// OPTIMAL APPROACH
int singleEle3(vector<int> v){
    int n = v.size();

    if(n==1) return v[0];
    if(v[0] != v[1]) return v[0];
    if(v[n-1] != v[n-2]) return v[n-1];

    int low=1 , high=n-2;

    while(low<=high){
        int mid = (low+high)/2;

        if(v[mid] != v[mid-1] && v[mid] != v[mid+1]) return v[mid];

        if((mid%2==1 && v[mid]==v[mid-1]) || (mid&2==0 && v[mid]==v[mid+1])) low=mid+1;
        else high=mid-1;
    }

    return -1;
}

int main(){
    vector<int> v = {1,1,2,3,3,4,4,5,5,6,6};
    cout<<singleEle3(v);

    return 0;
}