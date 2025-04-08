#include<iostream>
using namespace std;

// VARIATION-1
// int pascalTriangle1(int row , int col){
//     long long res = 1;

//     for(int i=0 ; i<col ; i++){
//         res = res*(row-i);
//         res = res/(i+1);
//     }

//     return res;
// }

// VARIATION-2
int pascalTriangle2(int row){
    long long res=1;
    cout<<res<<" ";

    for(int i = 1 ; i<row ; i++){
        res = res*(row-i);
        res= res/i;
        cout<<res<<" ";
    }

    return res;
}

int main(){
    // int row,col;
    // cin>>row>>col;
    
    // int ans1 = pascalTriangle1(row-1,col-1);
    // cout<<ans1;

    int row;
    cin>>row;

    pascalTriangle2(row);

    return 0;
}