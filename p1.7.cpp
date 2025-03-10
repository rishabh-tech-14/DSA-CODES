#include<iostream>
using namespace std;

int fib(int a){
    if(a<=1){
        return a;
    }
    return fib(a-1)+fib(a-2);
}

int main(){
    int n;
    cin>>n;
    for(int i =0 ; i<n ; i++){
        cout<<fib(i)<<" ";
    }

    return 0;
}