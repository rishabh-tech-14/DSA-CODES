#include<iostream>
#include<algorithm>
using namespace std;

// BRUTE-FORCE APPROACH
void mergeTwoArray1(int arr1[] , int arr2[] , int n , int m){
    int arr3[n+m];
    int left=0;
    int right=0;
    int index=0;

    while(left<n && right<m){
        if(arr1[left]<=arr2[right]){
            arr3[index]=arr1[left];
            index++,left++;
        }
        else{
            arr3[index]=arr2[right];
            index++,right++;
        }
    }

    while(left<n){
        arr3[index]=arr1[left];
        index++,left++;
    }

    while(right<m){
        arr3[index]=arr2[right];
        index++,right++;
    }

    for(int i = 0 ; i<n+m ; i++){
        if(i<n) arr1[i]=arr3[i];
        else arr2[i-n]=arr3[i];
    }
}

// OPTIMAL APPROACH - 1
void mergeTwoArray2(int arr1[] , int arr2[] , int n , int m){
    int left=n-1;
    int right=0;

    while(left>=0 && right<m){
        if(arr1[left]>arr2[right]){
            swap(arr1[left],arr2[right]);
            left--,right++;
        }
        else break;
    }

    sort(arr1,arr1+n);
    sort(arr2,arr2+m);
}

// OPTIMAL APPROACH - 2
void swapIfGreater(int arr1[] , int arr2[] , int ind1 , int ind2){
    if(arr1[ind1]>arr2[ind2]){
        swap(arr1[ind1],arr2[ind2]);
    }
}

void mergeTwoArray3(int arr1[] , int arr2[] , int n , int m){
    int len = n+m;
    int gap = (len/2)+(len%2);

    while(gap>0){
        int left = 0 ;
        int right = left+gap;

        while(right<len){
            if(left<n && right>=n){
                swapIfGreater(arr1,arr2,left,right-n);
            }
            else if(left>=n){
                swapIfGreater(arr2,arr2,left-n,right-n);
            }
            else{
                swapIfGreater(arr1,arr1,left,right);
            }
            left++;
            right++;
        }

        if(gap==1) break;
        gap=(gap/2)+(gap%2);
    }
}

int main(){
    int n=4 , m=3;
    int arr1[] = {1, 4, 8, 10};
    int arr2[] = {2, 3, 9};

    mergeTwoArray3(arr1,arr2,n,m);

    for(int i = 0 ; i<n ; i++){
        cout<<arr1[i]<<" ";
    }

    for(int i = 0 ; i<m ; i++){
        cout<<arr2[i]<<" ";
    }

    return 0;
}