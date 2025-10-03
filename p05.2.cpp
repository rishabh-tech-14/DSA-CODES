#include<iostream>
#include<vector>
#include<map>
#include<climits>
using namespace std;

// BRUTE-FORCE APPROACH
vector<int> MajorityElement1(vector<int> v){
    int n = v.size();
    vector<int> ls;

    for(int i = 0 ; i<n ; i++){
        if(ls.size()==0 || ls[0]!=v[i]){
            int cnt = 0 ;
            for(int j = 0 ; j<n ; j++){
                if(v[j]==v[i]){
                    cnt++;
                }
            }

            if(cnt>(n/3)){
                ls.emplace_back(v[i]);
            }

            if(ls.size()==2) break;
        }
    }

    return ls;
}

// BETTER APPROACH
vector<int> MajorityElement2(vector<int> v){
    int n = v.size();
    map<int,int> mpp;
    int cnt =0;
    int mini = int(n/3);
    vector<int> ls;

    for(int i = 0 ; i<n ; i++){
        mpp[v[i]]++;

        if(mpp[v[i]] == mini+1){
            ls.emplace_back(v[i]);
        }

        if(ls.size()==2) break;
    }

    return ls;

}

// OPTIMAL APPROACH
vector<int> MajorityElement3(vector<int> v){
    int n = v.size();
    int cnt1=0 , cnt2=0;
    int ele1 =INT_MIN;
    int ele2 = INT_MIN;
    vector<int> ls;

    for(int i = 0 ; i<n ; i++){
        if(cnt1==0 && ele2 != v[i]){
            cnt1 = 1;
            ele1 = v[i];
        }

        else if(cnt2==0 && ele1 != v[i]){
            cnt2=1;
            ele2=v[i];
        }

        else if(ele1 == v[i]) cnt1++;

        else if(ele2 == v[i]) cnt2++;

        else{
            cnt1--;
            cnt2--;
        }
    }

    cnt1 = 0 ;
    cnt2 = 0;
    int mini = n/3;

    for(int i = 0 ; i<n ; i++){
        if(ele1 == v[i]){
            cnt1++;
            if(cnt1==mini+1) ls.emplace_back(ele1);
        }
        else if(ele2 == v[i]){
            cnt2++;
            if(cnt2==mini+1) ls.emplace_back(ele2);
        }
    }

    

    

    return ls;
}

int main(){
    int n;
    cin>>n;
    vector<int> v;
    for(int i = 0 ; i<n ; i++){
        int a;
        cin>>a;
        v.push_back(a);
    }

    vector<int> ans = MajorityElement3(v);
    for(auto it : ans){
        cout<<it<<" ";
    } 


    return 0;
}