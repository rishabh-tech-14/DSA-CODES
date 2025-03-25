#include<bits/stdc++.h>
using namespace std;

int missingNumber(int a[] , int n){
    int flag;

    for(int i = 1 ; i<=n ; i++){
        flag=0;
        for(int j = 0 ; j<n-1 ; j++){
            if(a[j]==i){
                flag=1;
                break;
            }
        }
        if(flag==0){
            return i;
        }
    }

    return -1;
}

int main(){
    int arr[] = {1,4,2,5};
    cout<<missingNumber(arr,5);
        
    return 0;
}