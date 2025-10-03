#include<iostream>
using namespace std;

void selection_sort(int a[] , int k){
    for(int i = 0 ; i<=k-2 ; i++){
        int min = i;
        for(int j = i ; j<=k-1 ; j++ ){
            if(a[j]<a[min]){
                min = j;
            }
        }
        swap(a[min],a[i]);
    }
}

void bubble_sort(int a[] , int k){
    for(int i = 0 ; i<=k-2 ; i++){
        bool check=false;
        for(int j=0 ; j<k-1 ; j++){
            if(a[j]>a[j+1]){
                swap(a[j],a[j+1]);
                check=true;
            }
        }
        if(check==false) break;
    }
}

void insertion_sort(int a[], int k){
    for(int i = 0 ; i<=k-1 ; i++){
        int j=i;
        while(j>0 && a[j-1]>a[j]){
            swap(a[j-1],a[j]);
            j--;
        }
    }

}

int main(){
    int n;
    cin>>n;

    int arr[n];
    for(int i = 0 ; i<n ; i++){
        cin>>arr[i];
    }

    // selection_sort(arr,n);
    // bubble_sort(arr,n);
    insertion_sort(arr,n);

    for(int i = 0 ; i<n ; i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}