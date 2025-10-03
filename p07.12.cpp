#include<iostream>
#include<vector>
#include<climits>
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

// BETTER APPROACH
double median2(vector<int> arr1 , vector<int> arr2){
    int n1 = arr1.size();
    int n2 = arr2.size();
    int n = (n1+n2);

    int ind2 = (n/2);
    int ind1 = (n/2)-1;

    double ind1ele = -1 , ind2ele = -1;

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

// OPTIMAL APPROACH
double median3(vector<int> arr1 , vector<int> arr2){
    int n1 = arr1.size();
    int n2 = arr2.size();

    int n = n1+n2;

    if(n1>n2) return median3(arr2 ,arr1);

    int left = (n1+n2+1)/2;

    int low = 0 , high = n1;

    while(low<=high){
        int mid1 = (low+high)/2;

        int mid2 = left-mid1;

        int l1 = INT_MIN , l2 = INT_MIN;
        int r1 = INT_MAX , r2 = INT_MAX;

        if(mid1<n1) r1 = arr1[mid1];
        if(mid2<n2) r2 = arr2[mid2];
        if(mid1-1>=0) l1 = arr1[mid1-1];
        if(mid2-1>=0) l2 = arr2[mid2-1];

        if(l1<r2 && l2<r1){
            if(n%2==1) return max(l1,l2);

            return double(((max(l1,l2)+min(r1,r2))/2.0));
        }

        else if(l2>r1) low=mid1+1;
        else high = mid1-1;
    }

    return 0;

}

int main(){
    vector<int> arr1 = {1, 4, 7, 10, 12};
    vector<int> arr2 = {2, 3, 6, 15,17};

    cout<<median3(arr1,arr2);

    return 0;
}