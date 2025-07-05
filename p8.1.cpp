#include<iostream>
#include<vector>
using namespace std;

// BRUTE-FORCE APPROACH
int rowWithMax1s1(vector<vector<int>> arr , int n , int m){
    int max_cnt = -1;
    int index = -1;

    for(int i = 0 ; i<n ; i++){
        int cnt_ones = 0;

        for(int j = 0 ; j<m ; j++){
            cnt_ones += arr[i][j];
        }

        if(cnt_ones>max_cnt){
            max_cnt = cnt_ones;
            index = i;
        }
    }

    return index;
}

// OPTIMAL APPROACH
int lowerBound(vector<int> arr , int m , int k){
    int low=0 , high=m;
    int ans = m;

    while(low<=high){
        int mid = (low+high)/2;

        if(arr[mid]>=k){
            ans = mid;
            high=mid-1;
        }

        else low=mid+1;
    }

    return ans;
}
int rowWithMax1s2(vector<vector<int>> arr , int n , int m){
    int max_cnt = 0;
    int index = -1;

    for(int i = 0 ; i<n ; i++){
        int cnt_ones = 0;
        cnt_ones = m-lowerBound(arr[i],m,1);

        if(cnt_ones>max_cnt){
            max_cnt = cnt_ones;
            index = i;
        }
    }

    return index;   
}

int main(){
    vector<vector<int>> arr = {{0, 1, 1}, {0, 0, 1}, {1, 1, 1}};
    int n = 3, m = 3;
    cout<<rowWithMax1s2(arr,n,m);
    return 0;
}