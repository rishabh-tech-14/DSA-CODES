#include<iostream>
#include<vector>
using namespace std;

// BRUTE-FORCE APPROACH
vector<int> FindMissingNumber1(vector<int> v){
    int n = v.size();
    int repeating = -1 , missing = -1;

    for(int i = 1 ; i<=n ; i++){
        int cnt=0;
        for(int j=0 ; j<n ; j++){
            if(v[j]==i) cnt++;
            else continue;
        }

        if(cnt==2) repeating=i;
        else if(cnt==0) missing=i;

        if(repeating!=-1 && missing!=-1) break;
    }

    return {repeating,missing};

}

// BETTER APPROACH
vector<int> FindMissingNumber2(vector<int> v){
    int n = v.size();
    int repeating=-1 , missing=-1;

    int hash[n+1] = {0};
    for(int i = 0 ; i<n ; i++){
        hash[v[i]]++;
    }

    for(int i = 1 ; i<n ; i++){
        if(hash[i]==2) repeating=i;
        else if(hash[i]==0) missing=i;

        if(repeating!=-1 && missing!=-1) break;
    }

    return {repeating,missing};
}

// OPTIMAL APPROACH
vector<int> FindMissingNumber3(vector<int> v){
    int n = v.size();
    int repeating = -1 , missing = -1;

    int sn = (n*(n+1))/2;
    int s2n = (n*(n+1)*(2*n+1))/6;

    int s1=0, s2=0;

    for(int i = 0 ; i<n ; i++){
        s1 += v[i];
        s2 += v[i]*v[i];
    }

    int val1 = s1-sn;
    int val2 = s2-s2n;
    val2 = val2/val1;

    repeating = (val1+val2)/2;
    missing = (val2-val1)/2;

    return {repeating,missing};
}

int main(){
    int n;
    cin>>n;
    vector<int> v;
    for(int i = 0 ; i<n ; i++){
        int a;
        cin>>a;
        v.push_back(a);
    }

    vector<int> ans = FindMissingNumber3(v);
    cout<<"Repeating : "<<ans[0]<<" Missing : "<<ans[1];

    return 0;
}