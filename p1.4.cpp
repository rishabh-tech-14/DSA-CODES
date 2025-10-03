#include<iostream>
using namespace std;

// PARAMETERISED RECURSION
// int fact(int a,int facto){
//     if(a<1) return facto;
//     fact(a-1, facto*a);
// }

// FUNCTIONAL RECURSION
int fact(int a){
    if(a<1) return 1;
    return a*fact(a-1);
}

int main(){
    int n;
    cin>>n;
    // cout<<fact(n,1);
    cout<<fact(n);

    return 0;
}