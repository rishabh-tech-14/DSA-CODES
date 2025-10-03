#include<iostream>
#include<vector>
using namespace std;

// BRUTE-FORCE APPROACH
pair<int,int> firstandlastoccurance1(vector<int> &v , int k){
    int n = v.size();
    int first=-1 , last=-1;
    
    for(int i = 0 ; i<n ; i++){
        if(v[i]==k){
            if(first==-1) first=i;
            last=i;
        }
    }

    return {first,last};
}

// BETTER APPROACH
int lowerbound(vector<int> v , int k){
    int n = v.size();
    int low = 0 , high = n-1;
    int first = -1;

    while(low<=high){
        int mid = (low+high)/2;

        if(v[mid]==k){
            first=mid;
            high=mid-1;
        }
        else if (v[mid]>k) high=mid-1;
        else low=mid+1;
    }

    return first;
}

int upperbound(vector<int> v , int k){
    int n = v.size();
    int low = 0 , high = n-1;
    int second = -1;

    while(low<=high){
        int mid = (low+high)/2;

        if(v[mid]==k){
            second=mid;
            low=mid+1;
        }
        else if (v[mid]>k) high=mid-1;
        else low=mid+1;
    }

    return second;
}

pair<int,int> firstandlastoccurance2(vector<int> &v , int k){
    int n = v.size();

    int lb = lowerbound(v,k);
    if(lb==-1) return {-1,-1};

    return {lb,upperbound(v,k)};

}

// OPTIMAL APPROACH
int firstoccurance(vector<int> v , int k){
    int n = v.size();
    int low = 0 , high = n-1;
    int first = -1;

    while(low<=high){
        int mid = (low+high)/2;

        if(v[mid]==k){
            first=mid;
            high=mid-1;
        }
        else if(v[mid]<k) low=mid+1;
        else high=mid-1;
    }

    return first;
}

int secondoccurance(vector<int> v , int k){
    int n = v.size();
    int low = 0 , high = n-1;
    int second = -1;

    while(low<=high){
        int mid = (low+high)/2;

        if(v[mid]==k){
            second=mid;
            low=mid+1;
        }
        else if(v[mid]<k) low=mid+1;
        else high=mid-1;
    }

    return second;
}

pair<int,int> firstandlastoccurance3(vector<int> v , int k){
    int f = firstoccurance(v,k);
    if(f==-1) return {-1,-1};
    return {f,secondoccurance(v,k)};
}

int main(){
    vector<int> v = {1, 2, 2, 2, 3};

    pair<int,int> ans = firstandlastoccurance3(v,1);
    cout<<ans.first<<endl<<ans.second;

    return 0;
}