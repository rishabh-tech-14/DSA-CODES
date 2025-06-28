#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
using namespace std;

// BRUTE-FORCE APPROACH
int paintersCnt(vector<int> boards , int k){
    int n = boards.size();
    int paint = 1;
    int bCnt = 0;

    for(int i = 0 ; i<n ; i++){
        if(bCnt+boards[i]<=k){
            bCnt += boards[i];
        }
        else{
            paint++;
            bCnt = boards[i];
        }
    }

    return paint;
}
int boardsAllocation(vector<int> boards , int painters){
    int n = boards.size();

    int low=*max_element(boards.begin(),boards.end());
    int high = accumulate(boards.begin(),boards.end(),0);

    for(int i = low ; i<=high; i++){
        int cnt = paintersCnt(boards,i);

        if(cnt==painters){
            return i;
        }
        else continue;
    }
}

// OPTIMAL APPROACH
int paintersCnt2(vector<int> boards , int k){
    int n = boards.size();

    int paint = 1;
    int bCnt = 0;

    for(int i = 0 ; i<n ; i++){
        if(bCnt+boards[i]<=k){
            bCnt += boards[i];
        }
        else{
            paint++;
            bCnt = boards[i];
        }
    }

    return paint;
}
int boardsAllocation2(vector<int> boards , int painters){
    int low = *max_element(boards.begin(),boards.end());
    int high = accumulate(boards.begin(),boards.end(),0);

    while(low<=high){
        int mid = (low+high)/2;

        int cnt = paintersCnt2(boards,mid);

        if(cnt>painters) low=mid+1;
        else high=mid-1;
    }

    return low;
}

int main(){
    vector<int> boards = {10, 20, 30, 40};
    int painters = 2;

    cout<<boardsAllocation2(boards,painters);
    return 0;
}