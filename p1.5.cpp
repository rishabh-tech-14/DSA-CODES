#include<iostream>
using namespace std;

void reverseArr(int arr[] , int i , int e){
    if(i>e) return;
    swap(arr[i],arr[e]);
    reverseArr(arr,i+1,e-1);
}

int main(){
    int s;
    cin>>s;
    int a[s];
    for(int i=0 ; i<s ; i++){
        cin>>a[i];
    }
    reverseArr(a,0,s-1);
    for(int i=0 ; i<s ; i++){
        cout<<a[i]<<" ";
    }
}