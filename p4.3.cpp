#include<bits/stdc++.h>
using namespace std;

bool chksort(int a[] , int b){
    for(int i = 1 ; i<b ; i++){
        for(int j = 0 ; j<i ; j++){
            if(a[j]>a[i]) return false;
        }
    }
    return true;
}

bool checksort(int a[], int b){
    for(int i = 1 ; i<=b ; i++){
        if(a[i]<a[i-1]) return false;
    }
    return true;
}

int main(){
    int a;
    cin>>a;
    int arr[a];
    for(int i =0 ; i<a ; i++){
        cin>>arr[i];
    }
    cout<<chksort(arr,a);
    cout<<endl;
    cout<<checksort(arr,a);

    return 0;
}