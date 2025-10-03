#include<bits/stdc++.h>
using namespace std;

int main(){

    /*
    //PAIR

    pair<int , int> p = {1,2};
    cout<<p.first<<" "<<p.second<<endl;

    pair<int , pair<int , int>> o = {1,{1,2}};
    cout<<o.first<<endl;
    cout<<o.second.second<<" "<<o.second.first<<endl;

    pair<int , int> a[] = {{1,2},{3,4},{5,6},{7,8}};
    cout<<a[3].first<<endl;
    */


    /*
    //vector
    vector<int> v;
    v.push_back(3);
    v.push_back(2);
    v.push_back(1);
    v.emplace_back(5);

    vector<int> :: iterator it;
    for(it=v.begin() ; it!=v.end() ; it++){
        cout<<*(it)<<endl;
    }

    for(auto it=v.begin() ; it!=v.end() ; it++){
        cout<<*(it)<<endl;
    }

    vector<int> v1(5,100);
    for(auto it : v1){
        cout<<it<<" ";
    }
    cout<<endl;
    cout<<v.back();

    v.erase(v.begin(),v.begin()+2);
    
    v.insert(v.begin(),2,4);
    */

    //stack
    stack<int> st;
    st.push(1);
    st.push(9);
    st.push(6);
    
    cout<<st.top();
                
    return 0;
}