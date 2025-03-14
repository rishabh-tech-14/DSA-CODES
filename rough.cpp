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