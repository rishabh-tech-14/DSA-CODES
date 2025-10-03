#include<iostream>
using namespace std;

bool palindrome(string &a , int i){
    if(i>a.length()/2) return true;
    if(a[i] != a[a.length()-i-1]) return false;
    palindrome(a,i+1);    
    return true;
}

int main(){
    string s;
    cin>>s;
    cout<<palindrome(s,0);

}