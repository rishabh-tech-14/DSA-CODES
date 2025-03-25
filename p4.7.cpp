#include<bits/stdc++.h>
using namespace std;

vector<int> movezeros1(vector<int> a, int n){
    vector<int> temp;
    
    for(int i = 0 ; i<n ; i++){
        if(a[i]!=0){
            temp.emplace_back(a[i]);
        }
    }

    int vs = temp.size();

    for(int i = 0 ; i<vs ; i++){
        a[i]=temp[i];
    }

    for(int i = vs ; i<n ; i++){
        a[i]=0;
    }

    return a;
}

vector<int> movezeros2(vector<int> a , int n){
    int j = -1;
    for(int i = 0 ; i<n ; i++){
        if(a[i]==0){
            j=i;
            break;
        }        
    }
    
    if(j==-1) return a;
    
    for(int i = j+1 ; i<n ; i++){
        if(a[i]!=0){
            swap(a[i],a[j]);
            j++;
        }
    }

    return a;
}



int main(){
    int n;
    cin>>n;
    vector<int> arr;
    for(int i = 0 ; i<n ; i++){
        int b;
        cin>>b;
        arr.emplace_back(b);
    }

    // vector<int> q = movezeros(arr,n);
    // int u = q.size();

    // for(int i = 0 ; i<u ; i++){
    //     cout<<q[i]<<" ";
    // }

    vector<int> w = movezeros2(arr,n);
    int t = w.size();
    for (int i = 0; i < t; i++)
    {
        cout<<w[i]<<" ";
    }
    


    return 0;
}