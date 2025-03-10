#include<iostream>
using namespace std;

void func(string a,int x){
    int i = 0;
    if(x<=i) return;
    cout<<a<<endl;
    func(a,x-1);
}

int main(){
    string s;
    int a;
    getline(cin,s);
    cin>>a;
    func(s,a);

    return 0;
}