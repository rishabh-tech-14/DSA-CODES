#include<iostream>
#include<vector>
using namespace std;

// BRUTE-FORCE APPROACH
pair<int,int> searchMatrix1(vector<vector<int>> matrix , int target){
    int n = matrix.size();
    int m = matrix[0].size();

    for(int i = 0 ; i<n ; i++){
        for(int j = 0 ; j<m ; j++){
            if(matrix[i][j]==target){
                return {i,j};
            }
        }
    }

    return {-1,-1};

}

// BETTER APPROACH
bool BS(vector<int> arr , int target){
    int n = arr.size();
    int low = 0 , high = n-1;

    while(low<=high){
        int mid = (low+high)/2;

        if(arr[mid]==target) return true;

        else if(arr[mid]<target) low=mid+1;

        else high = mid-1;
    }

    return false;
}
bool searchMatrix2(vector<vector<int>> matrix , int target){
    int n = matrix.size();

    for(int i = 0 ; i<n ; i++){
        if(BS(matrix[i],target)) return true; 
    }

    return false;
}

// OPTIMAL APPROACH
pair<int,int> searchMatrix3(vector<vector<int>> matrix , int target){
    int n = matrix.size();
    int m = matrix[0].size();

    int row=0 , col=m-1;

    while(row<n && col>=0){
        if(matrix[row][col]==target) return {row,col};

        else if(matrix[row][col]<target) row++;
        else col--;
    }

    return {-1,-1};
}

int main(){
     vector<vector<int>> matrix = {{1, 4, 7, 11, 15}, {2, 5, 8, 12, 19},
                                  {3, 6, 9, 16, 22}, {10, 13, 14, 17, 24},
                                  {18, 21, 23, 26, 30}};

    // pair<int,int> ans = searchMatrix1(matrix,8);
    // cout<<ans.first<<","<<ans.second;

    // if(searchMatrix2(matrix,31)) cout<<"true";
    // else cout<<"false";

    pair<int,int> ans = searchMatrix3(matrix,8);
    cout<<ans.first<<","<<ans.second;

    return 0;
}