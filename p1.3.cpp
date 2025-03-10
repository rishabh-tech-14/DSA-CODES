#include<iostream>
using namespace std;

// PARAMETERISED RECURSION
// int sum(int i , int suum){
//     if(i<1) return suum;
//     sum(i-1,suum+i);
// }

// FUNCTIONAL RECURSION
int sum(int x){
    if(x<1) return 0;
    return x+sum(x-1);
}

int main(){
    int n;
    cin>>n;
    cout<<sum(n);

    return 0;
}