#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

// BRUTE-FORCE APPROACH
int median1(vector<vector<int>> matrix){
    int n = matrix.size();
    int m = matrix[0].size();

    vector<int> lst;

    for(int i = 0 ; i<n ; i++){
        for(int j = 0 ; j<m ; j++){
            lst.push_back(matrix[i][j]);
        }
    }

    sort(lst.begin(),lst.end());

    return lst[(n*m)/2];
}

// OPTIMAL APPROACH
int upperBound(vector<int> arr , int x){
    int n = arr.size();
    int ans = n;

    int low=0 , high=n-1;

    while(low<=high){
        int mid = (low+high)/2;

        if(arr[mid]>x){
            ans = mid;
            high=mid-1;
        }

        else low=mid+1;
    }

    return ans;
    
}
int cntSmallEquals(vector<vector<int>> matrix , int x){
    int n = matrix.size();
    int m = matrix[0].size();

    int cnt = 0;

    for(int i = 0 ; i<n ; i++){
        cnt += upperBound(matrix[i],x);
    }

    return cnt;
}
int median2(vector<vector<int>> matrix){
    int n = matrix.size();
    int m = matrix[0].size();

    int low=INT_MAX , high=INT_MIN;

    for(int i = 0 ; i<n ; i++){
        low = min(low,matrix[i][0]);
        high = max(high,matrix[i][m-1]);
    }

    int req = (m*n)/2;

    while(low<=high){
        int mid = (low+high)/2;

        int cntEq = cntSmallEquals(matrix,mid);

        if(cntEq<=req) low=mid+1;

        else high=mid-1;        
    }

    return low;
}

int main(){
    vector<vector<int>> matrix = {{1, 2, 3, 4, 5},{8, 9, 11, 12, 13},{21, 23, 25, 27, 29}};

    cout<<median2(matrix);

    return 0;
}