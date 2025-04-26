#include<iostream>
#include<vector>
using namespace std;

// BRUTE-FORCE APPROACH
int numberOfInversion1(vector<int> &arr , int n){
    int cnt=0;

    for(int i = 0 ; i<n ; i++){
        for(int j = i+1 ; j<n ; j++){
            if(arr[i]>arr[j]) cnt++;
        }
    }

    return cnt;
}

// OPTIMAL APPROACH
int merge(vector<int> &arr , int low , int mid , int high){
    vector<int> temp;
    int n = arr.size();
    int left = low;
    int right = mid+1;
    int cnt=0;

    while(left<=mid && right<=high){
        if(arr[left]<=arr[right]){
            temp.push_back(arr[left]);
            left++;
        }
        else{
            cnt += mid-left+1;
            temp.push_back(arr[right]);
            right++;
        }
    }

    while(left<=mid){
        temp.push_back(arr[left]);
        left++;
    }

    while(right<=high){
        temp.push_back(arr[right]);
        right++;
    }

    for(int i = low ; i<=high ; i++){
        arr[i]=temp[i-low];
    }

    return cnt;
}

int mergesort(vector<int> &arr , int low , int high){
    int cnt = 0;
    if(low>=high) return cnt;
    int mid = (low+high)/2;
    cnt += mergesort(arr,low,mid);
    cnt += mergesort(arr,mid+1,high);
    cnt += merge(arr,low,mid,high);

    return cnt;
}

int numberOfInversion2(vector<int> &arr , int n){
    int ans = mergesort(arr,0,n-1);
    return ans;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr = {2, 4, 1, 3, 5};

    cout<<numberOfInversion2(arr,n);

    return 0;
}