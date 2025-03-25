#include<iostream>
#include<set>
#include<vector>
using namespace std;

vector<int> findunion(vector<int> a , int n , vector<int> b , int m){
    set<int> s;
    vector<int> v;
    for(int i = 0 ; i<n ; i++){
        s.emplace(a[i]);
    }
    for(int i = 0 ; i<m ; i++){
        s.emplace(b[i]);
    }
    
    for(auto &it : s){
        v.emplace_back(it);
    }

    return v;
}

int main(){
    int a;
    cin>>a;
    vector<int> z;
    for(int i = 0 ; i<a ; i++){
        int l;
        cin>>l;
        z.emplace_back(l);
    }
    int s;
    cin>>s;
    vector<int> x;
    for(int i = 0 ; i<s ; i++){
        int k;
        cin>>k;
        x.emplace_back(k);
    }

    vector<int> q = findunion(z,a,x,s);
    int t = q.size();
    for(int i = 0 ; i<t ; i++){
        cout<<q[i]<<" ";
    }

    return 0;
}