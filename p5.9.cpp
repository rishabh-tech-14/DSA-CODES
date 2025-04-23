#include<iostream>
using namespace std;

int numberOfInversion(int arr[] , int n){
    int cnt=0;

    for(int i = 0 ; i<n ; i++){
        for(int j = i+1 ; j<n ; j++){
            if(arr[i]>arr[j]) cnt++;
        }
    }

    return cnt;
}

int main(){
    int n;
    cin>>n;
    int arr[n] = {2, 4, 1, 3, 5};

    cout<<numberOfInversion(arr,n);

    return 0;
}