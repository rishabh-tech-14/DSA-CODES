#include<iostream>
#include<vector>
using namespace std;

// BRUTE-FORCE APPROACH
double median1(vector<int> arr1 , vector<int> arr2){
    int n1 = arr1.size();
    int n2 = arr2.size();

    vector<int> arr3;

    int  i = 0 , j = 0;

    while(i<n1 && j<n2){
        if(arr1[i]<=arr2[j]){
            arr3.push_back(arr1[i]);
            i++;
        }
        else{
            arr3.push_back(arr2[j]);
            j++;
        }
    }

    while(i<n1){
        arr3.push_back(arr1[i]);
        i++;
    }

    while(j<n2){
        arr3.push_back(arr2[j]);
        j++;
    }

    int n = n1+n2;

    if(n%2==1) return arr3[n/2];
    return (double)(arr3[n/2]+(double)arr3[(n/2)-1])/2.0;
}

// OPTIMAL APPROACH
double median2(vector<int> arr1 , vector<int> arr2){
    int n1 = arr1.size();
    int n2 = arr2.size();
    int n = (n1+n2);

    int ind2 = (n/2);
    int ind1 = (n/2)-1;

    int ind1ele = -1 , ind2ele = -1;

    int cnt = 0 , i = 0 , j = 0;

    while(i<n1 && j<n2){
        if(arr1[i]<arr2[j]){
            if(cnt==ind1) ind1ele = arr1[i];
            if(cnt==ind2) ind2ele = arr1[i];
            i++;
            cnt++;
        }
        else{
            if(cnt==ind1) ind1ele = arr2[j];
            if(cnt==ind2) ind2ele = arr2[j];
            j++;
            cnt++;
        }
    }

    while(i<n1){
        if(cnt==ind1) ind1ele = arr1[i];
        if(cnt==ind2) ind2ele = arr1[i];
        i++;
        cnt++;
    }

    while(j<n2){
        if(cnt==ind1) ind1ele = arr2[j];
        if(cnt==ind2) ind2ele = arr2[j];
        j++;
        cnt++;
    }

    if(n%2==1) return ind2ele;
    return ((ind1ele+ind2ele)/2);    
}

int main(){
    vector<int> arr1 = {1, 4, 7, 10, 12};
    vector<int> arr2 = {2, 3, 6, 15};

    cout<<median2(arr1,arr2);

    return 0;
}