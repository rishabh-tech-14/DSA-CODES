#include<bits/stdc++.h>
#include<algorithm>

using namespace std;

int largeele(int a[] , int b){
    sort(a,a+b);
    return a[b-1];
}

int largeEle(int a[] , int b){
    int large = INT_MIN;
    for(int i =0 ; i<b ; i++){
        if(a[i]>large){
            large=a[i];
        }
    }

    return large;
}

int main(){
    int a;
    cin>>a;
    int arr[a];
    for(int i =0 ; i<a ; i++){
        cin>>arr[i];
    }

    cout<<largeele(arr,a);
    cout<<endl;
    cout<<largeEle(arr,a);

    return 0;
}