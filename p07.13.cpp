#include<iostream>
#include<vector>
#include<climits>
using namespace std;

// BRUTE-FORCE APPROACH
int kthElement1(vector<int> arr1 , vector<int> arr2 , int k){
    int n1 = arr1.size();
    int n2 = arr2.size();
    int i=0 , j=0;

    vector<int> arr3;

    while(i<n1 && j<n2){
        if(arr1[i]<arr2[j]){
            arr3.push_back(arr1[i]);
            i++;
        }
        else{
            arr3.push_back(arr2[j]);
            j++;
        }
    }

    while(i<n1){
        arr3.push_back(arr1[i]);
        i++;
    }

    while(j<n2){
        arr3.push_back(arr2[j]);
        j++;
    }

    return arr3[k-1];
}

// BETTER APPROACH
int kthElement2(vector<int> arr1 , vector<int> arr2 , int k){
    int n1 = arr1.size();
    int n2 = arr2.size();

    int ans = -1;
    int cnt = 0;

    int i = 0 , j=0;

    while(i<n1 && j<n2){
        if(arr1[i]<arr2[j]){
            ans = arr1[i];

            i++;
            cnt++;

            if(cnt==k) return ans;
        }
        else{
            ans = arr2[j];

            j++;
            cnt++;

            if(cnt==k) return ans;
        }        
    }

    while(i<n1){
        ans = arr1[i];

        i++;
        cnt++;

        if(cnt==k) return ans;
    }

    while(j<n2){
        ans = arr2[j]; 

        j++;
        cnt++;
        
        if(cnt==k) return ans;
    }

    return 0;
}

// OPTIMAL APPROACH
int kthElement3(vector<int> arr1 , vector<int> arr2 , int k){
    int n1 = arr1.size();
    int n2 = arr2.size();

    if(n1>n2) return kthElement3(arr2,arr1,k);

    int left = k;

    int low = max(0,k-n2) , high = min(k,n1);

    while(low<=high){
        int mid1 = (low+high)/2;

        int mid2 = left-mid1;

        int l1 = INT_MIN , l2 = INT_MIN;
        int r1 = INT_MAX , r2 = INT_MAX;

        if(mid1<n1) r1 = arr1[mid1];
        if(mid2<n2) r1 = arr2[mid2];
        if(mid1-1>=0) l1 = arr1[mid1-1];
        if(mid2-1>=0) l2 = arr2[mid2-1];

        if(l1<r2 && l2<r1){
            return max(l1,l2);
        }

        else if(l2>r1) low=mid1+1;
        else high= mid1-1;
    }
}

int main(){
    vector<int> arr1 = {1, 8, 10, 12};
    vector<int> arr2 = {2, 3, 9, 15,17};

    int k = 4;

    cout<<kthElement3(arr1,arr2,k);

    return 0;
}