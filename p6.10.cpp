#include<iostream>
#include<vector>
using namespace std;

// BRUTE-FORCE APPROACH
int peakEle1(vector<int> v){
    int n = v.size();

    for(int i = 0 ; i<n ; i++){
        if((i==0 || v[i]>v[i-1]) && (i==n-1 || v[i]>v[i+1])){
            return v[i];
        }
    }

    return -1;
}

// OPTIMAL APPROACH
int peakEle2(vector<int> v){
    int n = v.size();

    if(n==1) return v[0];
    if(v[0]>v[1]) return v[0];
    if(v[n-1]>v[n-2]) return v[n-1];

    int low = 1 , high=n-1;

    while(low<=high){
        int mid = (low+high)/2;

        if(v[mid]>v[mid-1] && v[mid]>v[mid+1]) return v[mid];

        else if(v[mid]>v[mid-1]) low=mid+1;

        else if(v[mid]>v[mid+1]) high=mid-1;
    }

    return -1;

}

int main(){
    vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 5, 1};
    cout<<peakEle2(v);

    return 0;
}