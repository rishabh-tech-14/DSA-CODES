#include<iostream>
#include<map>
using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0 ; i<n ; i++){
        cin>>arr[i];
    }

    map<int,int> mpp;
    for(int i=0 ; i<n ; i++){
        mpp[arr[i]]++;
    }

    for(auto it : mpp){
        cout<<it.first<<"->"<<it.second<<endl;
    }

    int q;
    cin>>q;
    while(q--){
        int a;
        cin>>a;
        cout<<mpp[a]<<endl;
    }

    return 0;
}

/*
FINDING FREQUENCY WITHOUT USING HASH METHOD

#include<iostream>
using namespace std;

int main(){
    int a;
    cin>>a;

    int arr[a];
    for(int i = 0 ; i<a ; i++){
        cin>>arr[i];
    }

    for(int i = 0 ; i<3 ; i++){
        int count = 0;
        int q;
        cin>>q;
        for(int j = 0 ; j<a ; j++){
            if(q==arr[j]){
                count +=1;
            }
            else continue;
            
        }
        cout<<count<<endl;
    }

    return 0;
}
*/
