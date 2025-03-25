#include<bits/stdc++.h>
using namespace std;

void secondele(int a[], int b){
    sort(a,a+b);
    for(int i = 0 ; i<b ; i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
    cout<<"1.Second smallest element is : "<<a[1]<<endl;
    cout<<"1.Second largest element is : "<<a[b-2]<<endl;
}

void secondlargest(int a[] , int b){
    int large = INT_MIN;
    int slarge = INT_MIN;
    if(b<2){
        cout<<"Error";
        return;
    }

    for(int i = 0 ; i<b ; i++){
        if(a[i]>large){
            slarge = large;
            large = a[i];
        }
        else if(a[i]<large && a[i]>slarge){
            slarge=a[i];
        }
    }
    if (slarge == INT_MIN) {  // No second largest element found
        cout << "Error: No second largest element found!" << endl;
        return ;
    }
    cout<<"2.Second largest element is : "<<slarge<<endl;
}

void secondsmallest(int a[] , int b){
    int small = INT_MAX;
    int ssmall = INT_MAX;

    for(int i =0 ; i<b ; i++){
        if(a[i]<small){
            ssmall = small;
            small = a[i];
        }
        else if(a[i]!=small && a[i]<ssmall){
            ssmall=a[i];
        }
    }
    cout<<"2.second smallest element is : "<<ssmall;
}

int main(){
    int a;
    cin>>a;
    int arr[a];
    for(int i = 0 ; i<a ; i++){
        cin>>arr[i];
    }
    secondele(arr,a);
    secondlargest(arr,a);
    secondsmallest(arr,a);
    
}