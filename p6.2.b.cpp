#include<iostream>
#include<vector>
using namespace std;

// BRUTE-FORCE APPROACH
int upperbound1(vector<int> v , int x){
    int n = v.size();

    for(int i = 0 ; i<n ; i++){
        if(v[i]>x){
            return i;
        }
    }

    return n;
}

// OPTIMAL APPROACH
int upperbound2(vector<int> v , int x){
    int n = v.size();
    int low = 0 , high = n-1;
    int ans = n;

    while(low<=high){
        int mid=(low+high)/2;

        if(v[mid]>x){
            ans = mid;
            high = mid-1;
        }

        else low = mid+1;

    }

    return ans;
}

int main(){
    vector<int> v = {1, 3, 5, 7, 9, 11, 13};
    cout<<upperbound2(v,7);

    return 0;
}