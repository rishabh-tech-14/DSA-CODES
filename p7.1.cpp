#include<iostream>
#include<cmath>
using namespace std;

// BRUTE-FORCE APPROACH
int sqrtt1(int n){
    int ans = 1;

    for(int i = 1 ; i<=n ; i++){
        if(i*i <= n){
            ans=i;
        }
        else break;
    }

    return ans;
}

// OPTIMAL APPROACH - 1
int sqrtt2(int n){
    int ans = sqrt(n);
    return ans;

}

// OPTIMAL APPROACH - 2
int sqrtt3(int n){
    int low=1 , high=n;
    int ans=1;

    while(low<=high){
        int mid = (low+high)/2;

        if(mid*mid<=n){
            ans=mid;
            low=mid+1;
        }

        else high=mid-1;
    }

    return ans;
}

int main(){
    int n = 48;
    cout<<sqrtt3(n);

    return 0;
}