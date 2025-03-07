#include<iostream>
using namespace std;

void print(int n){
    for(int i = 0 ; i<n ;i++){
        //space
        for(int j =0 ; j<n-i-1 ; j++){
            cout<<" ";
        }

        //numbers
        int breakpoint = (2*i+1)/2;
        int iniN = i+1;
        for(int j = 0 ; j<2*i+1 ; j++){
            cout<<iniN;
            if(j<breakpoint) iniN++;
            else iniN--;
        }

        //space
        for(int j =0 ; j<n-i-1 ; j++){
            cout<<" ";
        }
        cout<<endl;
    }
}

int main(){
    // int n=5;
    // print(n);
    int num = 70;
    cout<<__builtin_popcount(num);
    return 0;

}