#include<iostream>
using namespace std;

// ITERATIVE IMPLEMENTATION
int binarySearch1(int arr[] , int n , int target){
    int low = 0 , high = n-1;

    while(low<=high){
        int mid = (low+high)/2;
        
        if(arr[mid]==target){
            return mid;
        }

        else if(arr[mid]<target){
            low = mid+1;
        }

        else high = mid-1;
    }

    return -1;
}

// RECURSIVE APPROACH
int binarySearch2(int arr[] , int n , int low , int high , int target){
    if(low>high) return -1;

    int mid = (low+high)/2;

    if(arr[mid]==target) return mid;

    else if(arr[mid]<target){
        return binarySearch2(arr,n,mid+1,high,target);
    }

    else{
        return binarySearch2(arr,n,low,mid-1,target);
    }
}

int search(int arr[] , int n , int target){
    return binarySearch2(arr,n,0,n-1,target);
}

int main(){
    int arr[] = {1, 3, 5, 7, 9, 11, 13};
    int n = sizeof(arr)/sizeof(arr[0]);
    // cout<<binarySearch1(arr,n,7);
    cout<<search(arr,n,7);



    return 0;
}