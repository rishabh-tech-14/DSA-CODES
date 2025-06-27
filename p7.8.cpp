#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// BRUTE-FORCE APPROACH
bool canWePlace1(vector<int> stalls , int dist , int cows){
    int n = stalls.size();
    int cowscnt = 1;
    int last = stalls[0];

    for(int i = 1 ; i<=n-1 ; i++){
        if(stalls[i]-last>=dist){
            cowscnt++;
            last=stalls[i];
        }
        if(cowscnt>=cows) return true;
    }
    return false;
}
int aggressiveCows1(vector<int> stalls , int k){
    int n = stalls.size();
    sort(stalls.begin(),stalls.end());

    int limit = stalls[n-1]-stalls[0];

    for(int i = 1 ; i<=limit ; i++){
        if(canWePlace1(stalls,i,k)==false){
            return i-1;
        }
    }

    return limit;
}

// OPTIMAL APPROACH
bool canWePlace2(vector<int> stalls , int dist , int cows){
    int n = stalls.size();
    int cntCows = 1;
    int last = stalls[0];
    
    for(int i = 1 ; i<n ; i++){
        if(stalls[i]-last>=dist){
            cntCows++;
            last=stalls[i];
        }
        if(cntCows>=cows) return true;
    }

    return false;
}
int aggressiveCows2(vector<int> stalls , int k){
    int n = stalls.size();
    sort(stalls.begin(),stalls.end());

    int low=1 , high=stalls[n-1]-stalls[0];

    while(low<=high){
        int mid = (low+high)/2;

        if(canWePlace2(stalls,mid,k)==true){
            low=mid+1;
        }

        else high=mid-1;
    }

    return high;
    
}

int main(){
    vector<int> stalls = {0,3,4,7,10,9};
    int k=4;    

    cout<<aggressiveCows2(stalls,k);
    
    return 0;
}