#include<iostream>
#include<vector>
#include<climits>
#include<cmath>
using namespace std;

// BRUTE-FORCE APPROACH
int findMax1(vector<int> v){
    int n = v.size();
    int maxi = INT_MIN;

    for(int i = 0 ; i<n ; i++){
        maxi = max(maxi,v[i]);
    }

    return maxi;
}
int calculateHours1(vector<int> v , int hours){
    int n = v.size();
    int totalH = 0;

    for(int i = 0 ; i<n ; i++){
        totalH += ceil((double)v[i]/(double)hours);
    }

    return totalH;
}
int minRateToEatBanana1(vector<int> v , int hour){
    int maxi = findMax1(v);

    for(int i = 1 ; i<=maxi ; i++){
        int totalH = calculateHours1(v,i);

        if(totalH<=hour) return i;
    }

    return maxi;       
}

// OPTIMAL APPROACH
int findMax2(vector<int> v){
    int n = v.size();
    int maxi = INT_MIN;

    for(int i = 0 ; i<n ; i++){
        maxi = max(maxi,v[i]);
    }

    return maxi;
}
int calculateHours2(vector<int> v , int hourly){
    int n = v.size();
    int totalH = 0;

    for(int i = 0 ; i<n ; i++){
        totalH += ceil((double)v[i]/hourly);
    }

    return totalH;
}
int minRateToEatBanana2(vector<int> v, int hour){
    int maxi = findMax2(v);
    int low=1 , high=maxi;
    int ans = 0;

    while(low<=high){
        int mid = (low+high)/2;

        int reqTime = calculateHours2(v,mid);

        if(reqTime<=hour){
            ans = mid;
            high = mid-1;
        }
        else low=mid+1;
    }

    return ans;
}


int main(){
    vector<int> v = {7, 15, 6, 3};
    int hours = 8;

    cout<<minRateToEatBanana2(v,hours);

    return 0;
}