#include<iostream>
#include<vector>
using namespace std;

void printF(int ind , vector<int> ds , vector<int> &arr , int n){
    if(ind==n){
        for(auto it : ds){
            cout<<it<<" ";
        }

        if(ds.size()==0){
            cout<<"{}";
        }

        cout<<endl;

        return;
    }

    printF(ind+1,ds,arr,n);

    ds.push_back(ind);
    printF(ind+1,ds,arr,n);

    ds.pop_back();
    
}

int main(){
    vector<int> arr ={3,2,1};
    int n = 3;

    vector<int> a;

    printF(0,a,arr,n);

    return 0;
}