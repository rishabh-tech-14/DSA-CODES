#include<iostream>
#include<vector>
using namespace std;

void printS(int ind ,int s , int sum , vector<int> &ds , vector<int> &arr , int n){
    if(ind==n){
        if(s==sum){
            for(auto it : ds){
                cout<< it<<" ";
                cout<<endl;
            }

            return;
        }
    }

    ds.push_back(arr[ind]);
    s += arr[ind];

    printS(ind+1,s,sum,ds,arr,n);

    s -= arr[ind];
    ds.pop_back();

    printS(ind+1,s,sum,ds,arr,n);
}

int main(){
    vector<int> arr = {1,2,1};

    int sum = 2;
    
    vector<int> ds;

    printS(0 , 0 , sum , ds , arr , arr.size());

    return 0;
}