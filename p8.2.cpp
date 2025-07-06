#include<iostream>
#include<vector>
using namespace std;

// BRUTE-FORCE APPROACH
bool searchMatrix1(vector<vector<int>> matrix , int k){
    int n = matrix.size();
    int m = matrix[0].size();

    for(int i = 0 ; i<n ; i++){
        for(int j = 0 ; j<m ; j++){
            if(matrix[i][j]==k){
                return true;
            }
        }
    }

    return false;
}

// BETTER APPROACH
bool BS(vector<int> matrix , int k){
    int n = matrix.size();

    int low=0 , high=n-1;

    while(low<=high){
        int mid = (low+high)/2;

        if(matrix[mid]==k) return true;

        else if(matrix[mid]<k) low=mid+1;

        else high = mid-1;
    }

    return false;
}
bool searchMatrix2(vector<vector<int>> matrix , int k){
    int n = matrix.size();
    int m = matrix[0].size();

    for(int i = 0 ; i<n ; i++){
        if(matrix[i][0]<=k && k<=matrix[i][m-1]){
            return BS(matrix[i],k);
        }
    }

    return false;
}

// OPTIMAL APPROACH
int searchMatrix3(vector<vector<int>> matrix , int k){
    int n = matrix.size();
    int m = matrix[0].size();

    int low=0 , high = (n*m)-1;

    while(low<=high){
        int mid = (low+high)/2;

        int row=mid/m , col=mid%m;

        if(matrix[row][col]==k) return true;

        else if(matrix[row][col]<k) low=mid+1;

        else high=mid-1;
    }

    return false;
}

int main(){
    vector<vector<int>> matrix = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
    if(searchMatrix3(matrix, 5)) cout<<"true";
    else cout<<"false";
    return 0;
}