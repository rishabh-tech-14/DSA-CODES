#include<iostream>
using namespace std;

void leftrotate1(int a[] , int n){
    int temp[n];
    for(int i =0 ; i<n ; i++){
        temp[i]=a[i+1];
    }
    temp[n-1]=a[0];

    for(int i = 0 ; i<n ; i++){
        a[i]=temp[i];
    }
}

void leftrotate2(int a[] , int n){
    int temp = a[0];
    for(int i = 1 ; i<n ; i++){
        a[i-1] = a[i];
    }
    a[n-1]=temp;
}

int main(){
    int a;
    cin>>a;
    int arr[a];
    for(int i = 0 ; i<a ; i++){
        cin>>arr[i];
    }

    leftrotate1(arr,a);
    for(int i = 0 ; i<a ; i++){
        cout<<arr[i]<<" ";
    }

    cout<<endl;

    // leftrotate2(arr,a);    
    // for(int i = 0 ; i<a ; i++){
    //     cout<<arr[i]<<" ";
    // }

    return 0;
}

