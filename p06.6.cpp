#include<iostream>
#include<vector>
using namespace std;

// BRUTE-FORCE APPROACH
int search1(vector<int> v , int target){
    int n = v.size();

    for(int i = 0 ; i<n ; i++){
        if(v[i]==target) return i;
    }

    return -1;
}

// OPTIMAL APPROACH
int search2(vector<int> v , int target){
    int n = v.size();
    int low=0 , high=n-1;

    while(low<=high){
        int mid = (low+high)/2;

        if(v[mid]==target) return mid;

        if(v[0]<=v[mid]){
            if(v[0]<=target && target<=v[mid]){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }

        else{
            if(v[mid]<=target && target<=v[high]){
                low=mid+1;
            }
            else high=mid-1;
        }
    }

    return -1;
}

int main(){
    vector<int> v = {4,5,6,7,0,1,2};
    cout<<search2(v,0);

    return 0;
}