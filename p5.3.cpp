#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;

// BRUTE-FORCE APPROACH
vector<vector<int>> triplet1(vector<int> v){
    int n = v.size();
   
    set<vector<int>> st;

    for(int i = 0 ; i<n ; i++){
        for(int j = i+1 ; j<n ; j++){
            for(int k = j+1 ; k<n ; k++){
                if(v[i] + v[j] + v[k] == 0){
                    vector<int> temp = {v[i],v[j],v[k]};
                    sort(temp.begin(),temp.end());
                    st.insert(temp);
                }
            }
        }
    }

    vector<vector<int>> ans(st.begin(),st.end());
    return ans;
}

// BETTER-APPROACH
vector<vector<int>> triplet2(vector<int> v){
    set<vector<int>> st;
    int n = v.size();

    for(int i = 0 ; i<n ; i++){
        set<int> hashset;
        for(int j = i+1 ; j<n ; j++){
            int third = -(v[i]+v[j]);
            if(hashset.find(third) != hashset.end()){
                vector<int> temp = {v[i],v[j],third};
                sort(temp.begin(),temp.end());
                st.insert(temp);
            }

            hashset.insert(v[j]);
        }
    }

    vector<vector<int>> ans(st.begin(),st.end());
    return ans;
}

// OPTIMAL APPROACH
vector<vector<int>> triplet3(vector<int> v){
    int n = v.size();
    set<vector<int>> st;
    sort(v.begin(),v.end());

    for(int i = 0 ; i<n ; i++){
        if(i!=0 && v[i]==v[i-1]) continue;

        int j = i+1;
        int k = n-1;

        while(j<k){
            int sum = v[i]+v[j]+v[k];

            if(sum<0){
                j++;
            }

            else if(sum>0){
                k--;
            }

            else{
                vector<int> temp = {v[i],v[j],v[k]};
                st.insert(temp);
                j++;
                k--;

                while(j<k && v[i]==v[i-1]) j++;
                while(j<k && v[k]==v[k+1]) k++;
            }
        }
    }

    vector<vector<int>> ans(st.begin(), st.end());
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

    vector<vector<int>> ans = triplet3(v);

    for(auto it : ans){
        for(auto i : it){
            cout<<i<<" ";
        }
        cout<<endl;
    }



    return 0;
}