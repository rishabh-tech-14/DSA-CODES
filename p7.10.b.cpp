#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
using namespace std;

// BRUTE-FORCE APPROACH
int cntArr1(vector<int> arr , int asize){
    int n = arr.size();
    int aCnt = 1;
    int aSum = 0;

    for(int i = 0 ; i<n ; i++){
        if(aSum+arr[i]<=asize){
            aSum += arr[i];
        }
        else{
            aCnt++;
            aSum = arr[i];
        }
    }

    return aCnt;
}
int arraySplit1(vector<int> arr , int k){
    int low = *max_element(arr.begin(),arr.end());
    int high = accumulate(arr.begin(),arr.end(),0);

    for(int i = low ; i<=high ; i++){
        if(cntArr1(arr,i)==k) return i;
        else continue;
    }
}

// OPTIMAL APPROACH
int cntArr2(vector<int> arr , int asize){
    int n = arr.size();
    int aCnt = 1;
    int aSum = 0;

    for(int i = 0 ; i<n ; i++){
        if(aSum+arr[i]<=asize){
            aSum += arr[i];
        }
        else{
            aCnt++;
            aSum = arr[i];
        }
    }

    return aCnt;
}
int arraySplit2(vector<int> arr , int k){
    int low = *max_element(arr.begin(),arr.end());
    int high = accumulate(arr.begin(),arr.end(),0);

    while(low<=high){
        int mid = (low+high)/2;

        int cnt = cntArr2(arr,mid);

        if(cnt>k) low=mid+1;
        else high = mid-1;
    }

    return low;
}

int main(){
    vector<int> arr = {10, 20, 30, 40};
    int k = 2;

    cout<<arraySplit2(arr,k);

    return 0;
}