#include<iostream>
#include<vector>
using namespace std;

// BRUTE-FORCE APPROACH
int missingK1(vector<int> vec , int k){
    int n = vec.size();

    for(int i = 0 ; i<n ; i++){
        if(vec[i]<k) k++;
        else break;
    }

    return k;
}

// OPTIMAL APPROACH
int missingK2(vector<int> vec , int k){
    int n = vec.size();
    int low=0;
    int high=n-1;

    while(low<=high){
        int mid = (low+high)/2;

        int missing = (vec[mid]-(mid+1));

        if(missing<k) low=mid+1;
        else high=mid-1;
    }

    return (low+k);
}

int main(){
    vector<int> vec = {2,3,4,7,11};
    int k = 5;

    cout<<missingK2(vec,k);

    return 0;
}