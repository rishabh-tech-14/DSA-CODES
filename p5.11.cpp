#include<iostream>
#include<vector>
#include<climits>
using namespace std;

// BRUTE-FORCE APPROACH 
int maxProductSubarray1(vector<int> v , int n){
    int product = INT_MIN;

    for(int i = 0 ; i<n ; i++){
        for(int j = i ; j<n ; j++){
            int pro = 1;
            for(int k = i ; k<=j ; k++){
                pro *= v[k];
            }
            product = max(product,pro);
        }
    }

    return product;
}

// OPTIMAL APPROACH
int maxProductSubarray2(vector<int> v , int n){
    int product = INT_MIN;
    int prefix = 1;
    int suffix = 1;

    for(int i = 0 ; i<n ; i++){
        if(prefix==0) prefix=1;
        if(suffix==0) suffix=1;

        prefix *= v[i];
        suffix *= v[n-i-1];
        product = max(product,max(prefix,suffix));
    }

    return product;
}

int main(){
    int n;
    cin>>n;
    vector<int> v = {2, 3, -2, 4};
    cout<<maxProductSubarray2(v,n);

    return 0;
}