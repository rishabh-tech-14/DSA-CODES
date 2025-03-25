#include<bits/stdc++.h>
using namespace std;

int removedup(int a[] , int b){
    set<int> s;
    for(int i = 0 ; i<b ; i++){
        s.insert(a[i]);
    }

    int d=s.size();

    int j=0;
    for(auto it : s){
        a[j++]=it;
    }

    return d;
}

int remdup(int a[] , int b){
    int j=0;
    for(int i = 1 ; i<b ; i++){
        if(a[i]!=a[j]){
            j++;
            a[j]=a[i];            
        }
    }
    return j+1;
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i =0  ; i<n ; i++){
        cin>>arr[i];
    }

    int u = removedup(arr,n);
    for(int i =0  ; i<u ; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    int t = remdup(arr,n);
    for(int i =0  ; i<t ; i++){
        cout<<arr[i]<<" ";
    }




    return 0;
}