#include<iostream>
#include<vector>
#include<climits>
using namespace std;

// BRUTE-FORCE APPROACH
bool possible1(vector<int> v , int days , int m , int k){
    int n = v.size();
    int cnt=0 , noOfB=0;

    for(int i = 0 ; i<n ; i++){
        if(v[i]<=days){
            cnt++;
        }
        else{
            noOfB += (cnt/k);
            cnt=0;
        }
    }

    noOfB += (cnt/k);

    if(noOfB>=m) return true;
    else return false;
}
int roseGarden1(vector<int> v , int m , int k){
    int n = v.size();

    if(n<(m*k)) return -1;

    int maxi=INT_MIN , mini=INT_MAX;
    
    for (int i = 0; i < n; i++)
    {
        maxi=max(maxi,v[i]);
        mini=min(mini,v[i]);
    }

    for(int i = mini ; i<=maxi ; i++){        
        if(possible1(v,i,m,k)==true) return i;
    }

    return -1;    
}

// OPTIMAL-APPROACH
bool possible2(vector<int> v , int days , int m , int k){
    int n = v.size();
    int cnt = 0 , noOfB = 0;

    for(int i = 0 ; i<n ; i++){
        if(v[i]<=days){
            cnt++;
        }
        else{
            noOfB += (cnt/k);
            cnt=0;
        }
    }

    noOfB += (cnt/k);

    if(noOfB>=m) return true;
    else return false;
}
int roseGarden2(vector<int> v , int m , int k){
    int n = v.size();    
    int maxi=INT_MIN , mini=INT_MAX;
    
    if(n<(m*k)) return -1;

    for(int i = 0 ; i<n ; i++){
        mini=min(mini,v[i]);
        maxi=max(maxi,v[i]);
    }

    int low=mini , high=maxi;
    int ans=high;

    while(low<=high){
        int mid = (low+high)/2;

        if(possible2(v,mid,m,k)==true){
            ans=mid;
            high=mid-1;
        }
        else low=mid+1;
    }

    return ans;

}

int main(){
    vector<int> v = {7, 7, 7, 7, 13, 11, 12, 7};

    cout<<roseGarden2(v,2,3);


    return 0;
}