#include<iostream>
#include<vector>
#include<climits>
using namespace std;

// BRUTE-FORCE APPROACH
int findKIndex1(vector<int> v){
    int n = v.size();
    int ans=INT_MAX;
    int index = -1;

    for(int i = 0 ; i<n ; i++){
        if(v[i]<ans){
            ans=v[i];
            index=i;
        }
    }

    return index;

}

// OPTIMAL APPROACH
int findKIndex2(vector<int> v){
    int low=0 , high=v.size()-1;
    int ans=INT_MAX;
    int index = -1;

    while(low<=high){
        int mid = (low+high)/2;

        if(v[low]<=v[high]){
            if(v[low]<ans){
                ans=v[low];
                index=low;
            }
            
            low=mid+1;
        }

        if(v[low]<=v[mid]){
            if(v[low]<ans){
                ans=v[low];
                index=low;
            }
            
            low=mid+1;
        }

        else{
            if(v[mid]<ans){
                ans=v[mid];
                index=mid;
            }

            high=mid-1;
        }
    }

    return index;
}

int main(){
    vector<int> v = {4, 5, 6, 7, 0, 1, 2};
    cout<<findKIndex2(v);

    return 0;
}