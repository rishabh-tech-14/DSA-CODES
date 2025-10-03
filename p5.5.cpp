#include<iostream>
#include<vector>
#include<map>
using namespace std;

// BRUTE-FORCE APPROACH
int XorSubarray1(vector<int> v , int k){
    int n = v.size();
    
    int cnt = 0;

    for(int i = 0 ; i<n ; i++){
        for(int j=i ; j<n ; j++){
            int xorr = 0;
            for(int k = i ; k<=j ; k++){
                xorr=xorr^v[k];
                if(xorr==k){
                    cnt++;
                }
            }
        }
    }

    return cnt;
}

// BETTER APPROACH
int XorSubarray2(vector<int> v , int k){
    int n = v.size();
    
    int cnt = 0;

    for(int i = 0 ; i<n ; i++){
        int xorr = 0;
        for(int j=i ; j<n ; j++){
            xorr=xorr^v[j];
            if(xorr==k) cnt++;
        }
    }

    return cnt;
}

// OPTIMAL APPROACH
int XorSubarray3(vector<int> v , int k){
    int n = v.size();
    int cnt = 0;
    int xorr=0;
    map<int,int> mpp;
    mpp[xorr]++;
    

    for(int i = 0 ; i<n ; i++){
        xorr=xorr^v[i];
        int x = xorr^k;
        cnt = cnt + mpp[x];
        mpp[xorr]++;
    }

    return cnt;
}

int main(){
    int n;
    cin>>n;
    vector<int> v;
    for(int i = 0 ; i<n ; i++){
        int a;
        cin>>a;
        v.emplace_back(a);
    }

    int k;
    cin>>k;

    cout<<XorSubarray3(v,k);

    return 0;
}