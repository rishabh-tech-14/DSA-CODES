#include<iostream>
using namespace std;

// BRUTE-FORCE APPROACH
int func1(int n, int m){
    int ans = 1;

    for(int i = 1 ; i<=m ; i++){
        ans=ans*n;
    }

    return ans;
}
int nthroot1(int n , int m){
    for(int i = 1 ; i<=m ; i++){
        int val = func1(i,n);
        if(val==m) return i;
        else if(val>m) break;
    }
    return -1;
}

// OPTIMAL APPROACH
int func2(int mid , int n , int m){
    int ans = 1;

    for(int i = 1 ; i<=n ; i++){
        ans *= mid;
        if(ans>m) return 2;
    }

    if(ans==m) return 1;

    return 0;
}
int nthroot2(int n , int m){
    int low=1 , high=m;

    while(low<=high){
        int mid = (low+high)/2;

        int val = func2(mid,n,m);

        if(val==1) return mid;
        else if(val==0) low=mid+1;
        else high=mid-1;
    }

    return -1;
}

int main(){
    int n = 4;
    int m = 256;
    cout<<nthroot2(n,m);

    return 0;
}