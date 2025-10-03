#include<iostream>
using namespace std;

void leftrotate1(int a[] , int n , int k){
    int temp[k];
    for(int i = 0 ; i<k ; i++){
        temp[i] = a[i];
    }

    for (int i = 0; i <= n-k ; i++)
    {
        a[i] = a[i+k];
    }

    for (int i = n-k; i <n ; i++)
    {
        a[i]=temp[i-n+k];
    }    
}

void reverse(int a[], int n , int m){
    int start = n;
    int end = m;

    while(start<=end){
        int temp = a[start];
        a[start]=a[end];
        a[end]=temp;
        start++;
        end--;
    }
}

void leftrotate2(int a[], int n , int k){
    reverse(a,0,k-1);
    reverse(a,k,n-1);
    reverse(a,0,n-1);    
}

int main(){
    int a;
    cin>>a;
    int arr[a];
    for(int i = 0 ; i<a ; i++){
        cin>>arr[i];
    }
    int k;
    cin>>k;

    // leftrotate1(arr,a,k);
    // for(int i = 0 ; i<a ; i++){
    //     cout<<arr[i]<<" ";
    // }

    leftrotate2(arr,a,k);
    for(int i = 0 ; i<a ; i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}