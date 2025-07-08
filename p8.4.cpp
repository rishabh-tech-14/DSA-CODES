#include<iostream>
#include<vector>
using namespace std;

// BRUTE-FORCE APPROACH
bool isPeak(vector<vector<int>> mat , int i , int j , int n , int m){
    int curr = mat[i][j];

    if(i>0 && mat[i-1][j]>curr) return false;
    if(i<n-1 && mat[i+1][j]>curr) return false;
    if(j>0 && mat[i][j-1]>curr) return false;
    if(j<m-1 && mat[i][j+1]>curr) return false;

    return true;
}
pair<int,int> findPeak1(vector<vector<int>> &mat){
    int n = mat.size();
    int m = mat[0].size();

    for(int i = 0 ; i<n ; i++){
        for(int j = 0 ; j<m ; j++){
            if(isPeak(mat,i,j,n,m))
                return {i,j};            
        }
    }

    return {-1,-1};
}

// BETTER APPROACH
pair<int,int> findPeak2(vector<vector<int>> mat){
    int n = mat.size();
    int m = mat.size();

    for(int j = 0 ; j<m ; j++){
        int maxRow=0;

        for(int i = 1 ; i<n ; i++){
            if(mat[i][j]>mat[maxRow][j]){
                maxRow = i;
            }
        }

        int curr = mat[maxRow][j];

        int left = (j>0) ? mat[maxRow][j-1] : -1;
        int right = (j<m-1) ? mat[maxRow][j+1] : -1;

        if(curr>=left && curr>=right){
            return {maxRow,j};
        }
    }

    return {-1,-1};
}

// OPTIMAL APPROACH
pair<int,int> findPeak3(vector<vector<int>> &mat){
    int n = mat.size();
    int m = mat[0].size();

    int low=0 , high=m-1;

    while(low<=high){
        int mid = (low+high)/2;

        int maxRow = 0;

        for(int i = 1 ; i<n ; i++){
            if(mat[maxRow][mid]<mat[i][mid]) maxRow=i;
        }

        int left = (mid>0) ? mat[maxRow][mid-1] : -1;
        int right = (mid<m-1) ? mat[maxRow][mid+1] : -1;

        if(mat[maxRow][mid]>=left && mat[maxRow][mid]>=right){
            return {maxRow,mid};
        }

        else if(mat[maxRow][mid]<left) high=mid-1;

        else low=mid+1;
    }

    return {-1,-1};
}

int main(){
    vector<vector<int>> mat = {{10, 20, 15},{21, 30, 44},{7, 16, 32}};
    pair<int,int> ans = findPeak3(mat);

    cout<<ans.first<<","<<ans.second;

    return 0;
}