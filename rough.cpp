#include<iostream>
using namespace std;

int partition(int a[] , int low , int high){
    int pivot = a[low];
    int i = low;
    int j = high;
    while(i<j){
        while(a[i]<=pivot && i<=high-1){
            i++;
        }
        while(a[j]>=pivot && j>=low+1){
            j--;
        }
        if(i<j) swap(a[i],a[j]);
    }
    swap(a[low],a[j]);
    return j;
}

void quicksort(int a[] , int low , int high){
    if(low<high){
        int pindex = partition(a, low , high);
        quicksort(a,low,pindex-1);
        quicksort(a,pindex+1,high);
    }
}

int main(){
    int a[] = {1,4,2,6,5,4,9};
    quicksort(a,0,7-1);
    for(int i = 0 ; i<7; i++){
        cout<<a[i]<<" ";
    }

    return 0 ;
}