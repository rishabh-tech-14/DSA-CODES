#include<iostream>
#include<vector>
using namespace std;

// BRUTE-FORCE APPROACH
int reversePair1(vector<int> v, int n){
    int cnt = 0; 
    for(int i = 0 ; i<n-1 ; i++){
        for(int j=i+1 ; j<n ; j++){
            if(v[i]>(2*(v[j]))){
                cnt++;
            }
        }
    }

    return cnt;
}

// OPTIMAL APPROACH
void merge(vector<int> &v , int low , int mid , int high){
    vector<int> temp;
    int left = low;
    int right = mid+1;

    while(left<=mid && right<=high){
        if(v[left]<=v[right]){
            temp.push_back(v[left]);
            left++;
        }
        else{
            temp.push_back(v[right]);
            right++;
        }
    }

    while(left<=mid){
        temp.push_back(v[left]);
        left++;
    }

    while(right<=high){
        temp.push_back(v[right]);
        right++;
    }

    for(int i = low ; i<=high ; i++){
        v[i]=temp[i-low];
    }
}
int countpairs(vector<int> &v , int low , int mid , int high){
    int right= mid+1;
    int cnt = 0;

    for(int i = low ; i<=mid ; i++){
        while(right<=high && v[i]>(2*v[right])) right++;
        cnt = cnt + (right-(mid+1));
    }

    return cnt;
}
int mergesort(vector<int> &v , int low , int high){
    int cnt = 0;
    if(low>=high) return cnt;
    int mid = (low+high)/2;
    cnt += mergesort(v,low,mid);
    cnt += mergesort(v,mid+1,high);
    cnt += countpairs(v,low,mid,high);
    merge(v,low,mid,high);
    return cnt;
}
int reversePair2(vector<int> &v , int low , int high){
    return mergesort(v,low,high);    
}

int main(){
    int n;
    cin>>n;

    vector<int> v = {1, 3, 2, 3, 1};

    cout<<reversePair1(v,n);


    return 0;
}