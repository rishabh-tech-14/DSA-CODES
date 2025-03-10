#include<iostream>
using namespace std;

// WAP TO PRINT 1-N NUMBERS
// void printNum(int n , int i=1){
//     if(i>n) return;
//     cout<<i<<endl;
//     printNum(n,i+1);
// }

// WAP TO PRINT 1-N NUMBERS (BACKTRACKING)
// void printNum(int n , int i){
//     if(i<1) return;
//     printNum(n,i-1);
//     cout<<i<<endl;
// }

// WAP TO PRINT N-1 NUMBERS
// void printNum(int a , int i){
//     if(i<1) return;
//     cout<<i<<endl;
//     printNum(a,i-1);
// }

// WAP TO PRINT N-1 NUMBERS (BACKTRACKING)
void printNum(int a , int i){
    if(i>a) return;
    printNum(a,i+1);
    cout<<i<<endl;
}

int main(){
    int n;
    cin>>n;
    printNum(n,1);

    return 0;
}