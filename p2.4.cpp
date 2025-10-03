#include<iostream>
using namespace std;

int main(){
    int a;
    cin>>a;
    int arr[a];
    for(int i=0 ; i<a ; i++){
        cin>>arr[i];
    }

    int hash[7] = {0};
    for(int i = 0 ; i<a ; i++){
        hash[arr[i]]++;
    }

    int lf = a,count=0;
    int element=0;
    for(int i = 0 ; i<7 ; i++){
        if(hash[i]<lf && hash[i]>0){
            lf=hash[i];
            element=i;
        }
        else{
            if(hash[i]<lf){
                lf=hash[i];
                element=i;
            }         
        }
    }
    cout<<"The least frequency element : "<<element<<" and its frequency : "<<lf;

    return 0;
}