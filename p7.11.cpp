#include<iostream>
#include<vector>
#include<queue>
using namespace std;

// BRUTE-FORCE APPROACH
long double minimiseMaxDistance1(vector<int> arr , int k){
    int n = arr.size();
    vector<int> howMany(n-1,0);

    for(int gasStation = 1 ; gasStation<=k ; gasStation++){
        long double maxSection = -1;
        int maxIndex = -1;

        for(int i = 0 ; i<n-1 ; i++){
            int difference = arr[i+1]-arr[i];
            long double secLength = difference/(long double)(howMany[i]+1);

            if(secLength>maxSection){
                maxSection = secLength;
                maxIndex = i;
            }
        }

        howMany[maxIndex]++;
    }

    long double maxAns = -1;

    for(int i = 0 ; i<n-1 ; i++){
        int difference = arr[i+1]-arr[i];
        long double secLength = difference/(long double)(howMany[i]+1);

        maxAns = max(maxAns,secLength);
    }

    return maxAns;
}

// BETTER APPROACH
long double minimiseMaxDistance2(vector<int> arr , int k){
    int n = arr.size();
    vector<int> howMany(n-1,0);

    priority_queue<pair<long double , int>> pq;

    for(int i = 0 ; i<n-1 ; i++){
        pq.push({arr[i+1]-arr[i],i});
    }

    for(int gasStation = 1 ; gasStation<=k ; gasStation++){
        auto r = pq.top();
        pq.pop();
        int secIndex = r.second;

        howMany[secIndex]++;

        long double iniDifference = arr[secIndex+1]-arr[secIndex];
        long double newSecLength = iniDifference/(long double)(howMany[secIndex]+1);

        pq.push({newSecLength,secIndex});
    }

    return pq.top().first;
}

int main(){
    vector<int> arr = {1, 2, 3, 4, 5};
    int k = 4;

    cout<<minimiseMaxDistance2(arr,k);

    return 0;
}