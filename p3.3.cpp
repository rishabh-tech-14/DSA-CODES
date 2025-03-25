#include<iostream>
#include<vector>
using namespace std;

int partition(vector<int> &arr , int low , int high){
    int pivot = arr[low];
    int i = low;
    int j= high;

    while(i<j){
        while(arr[i]<=pivot && i<=high-1){
            i++;
        }
        while(arr[j]>pivot && j>=low+1){
            j--;
        }
        if(i<j) swap(arr[i],arr[j]);
    }

    swap(arr[j],arr[low]);
    return j;
}

void qs(vector<int> &arr ,int low ,int high){
    if(low<high){
        int pIndex = partition(arr,low,high);
        qs(arr,low,pIndex-1);
        qs(arr,pIndex+1,high);
    }
}

// vector<int> vt(vector<int> &arr){
//     qs(arr,0,arr.size()-1);
// }

int main(){

    vector<int> v = {5,4,3,2,1};
    int n=v.size();

    cout<<"Before sorting."<<endl;
    for(int i = 0 ; i<n ; i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;

    qs(v,0,n-1);

    cout<<"After sorting."<<endl;

    for(int i = 0 ; i<n ; i++){
        cout<<v[i]<<" ";
    }

    return 0;
}