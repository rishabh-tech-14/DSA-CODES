#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;

// BRUTE-FORCE APPROACH
vector<vector<int>> fourSum1(vector<int> v , int target){
    int n = v.size();
    set<vector<int>> st;

    for(int i = 0 ; i<n ; i++){
        for(int j = i+1 ; j<n ; j++){
            for(int k = j+1 ; k<n ; k++){
                for(int l = k+1 ; l<n ; l++){
                    if(v[i]+v[j]+v[k]+v[l]==target){
                        vector<int> temp = {v[i],v[j],v[k],v[l]};
                        sort(temp.begin(),temp.end());
                        st.emplace(temp);
                    }
                }
            }
        }
    }

    vector<vector<int>> ans(st.begin(),st.end());
    return ans;
}

// BETTER APPROACH
vector<vector<int>> fourSum2(vector<int> v, int target){
    int n = v.size();
    set<vector<int>> st;

    for(int i = 0 ; i<n ; i++){
        for(int j = i+1 ; j<n ; j++){
            set<int> hashset;
            for(int k = j+1 ; k<n ; k++){
                int sum = v[i]+v[j]+v[k];
                int an = target-sum;

                if(hashset.find(an) != hashset.end()){
                    vector<int> temp ={v[i],v[j],v[k],an};
                    sort(temp.begin(),temp.end());
                    st.insert(temp);
                }

                hashset.insert(sum);
            }
        }
    }

    vector<vector<int>> ans(st.begin(),st.end());
    return ans;
    
}

// OPTIMAL APPROACH
vector<vector<int>> fourSum3(vector<int> v,int target){
    int n = v.size();
    sort(v.begin(),v.end());
    vector<vector<int>> ans;

    for(int i = 0 ; i<n ; i++){
        if(i!=0 && v[i]==v[i-1]) continue;
        for(int j = i+1 ; j<n ; j++){
            if(j!=i+1 && v[j]==v[j-1]) continue;

            int k = j+1;
            int l = n-1;

            while(k<l){
                int sum = v[i]+v[j]+v[k]+v[l];

                if(sum<target) k++;

                else if(sum>target) l--;

                else{
                    vector<int> temp = {v[i],v[j],v[k],v[l]};
                    ans.emplace_back(temp);
                    k++;
                    l--;
                    while(k<l && v[k]==v[k-1]) k++;
                    while(k<l && v[l]==v[l+1]) l--;
                }

                
            }
        }
    }

    return ans;
}

int main(){
    int n;
    cin>>n;
    vector<int> v;
    for(int i = 0 ; i<n ; i++){
        int a;
        cin>>a;
        v.emplace_back(a);
    }

    vector<vector<int>> ans = fourSum3(v,0);
    for(auto it1 : ans){
        for(auto it2 : it1){
            cout<<it2<<" ";
        }
        cout<<endl;
    }

    return 0;
}