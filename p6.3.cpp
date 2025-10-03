#include<iostream>
#include<vector>
using namespace std;

int floor(vector<int> v , auto x){
    int n = v.size();
    int low = 0 , high = n-1;
    int ans = -1;

    while(low<=high){
        int mid = (low+high)/2;

        if(v[mid]<=x){
            ans = mid;
            low = mid+1;
        }
        else high = mid-1;
    }

    return ans;
}

int ceil(vector<int> v , auto x){
    int n = v.size();
    int low = 0 , high = n-1;
    int ans = -1;

    while(low<=high){
        int mid = (low+high)/2;

        if(v[mid]>=x){
            ans = mid;
            high = mid-1 ;
        }
        else low = mid+1;
    }

    return ans;
}

pair<int,int> floorandceil(vector<int> v , auto x){
    int f = floor(v,x);
    int c = ceil(v,x);

    return make_pair(f,c);
}

int main(){
    vector<int> v = {1, 3, 5, 7, 9, 11, 13};
    double n = 7.5;

    pair<int,int> ans = floorandceil(v,n);
    cout<<v[ans.first]<<endl<<v[ans.second];

    return 0;
}