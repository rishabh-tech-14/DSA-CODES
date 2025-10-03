#include<iostream>
#include<vector>
using namespace std;

// BRUTE-FORCE APPROACH
int ncr(int row , int col){
    long long ans = 1;

    for(int i = 0 ; i<col ; i++){
        ans = ans*(row-i);
        ans = ans/(i+1);
    }

    return ans;
}

vector<vector<int>> pascalTriangle(int row){
    vector<vector<int>> ans;

    for(int i = 1; i<=row ; i++){
        vector<int> temp;
        for(int j =1 ; j<=i ; j++){
            temp.push_back(ncr(i-1,j-1));
        }

        ans.push_back(temp);
    }

    return ans;
}


// OPTIMAL-APPROACH
void generaterow(int row){
    int ans = 1;
    cout<<ans<<" ";

    for(int i = 1 ; i<row ; i++){
        ans = ans*(row-i);
        ans=ans/i;
        cout<<ans<<" ";
    }
}

vector<vector<int>> pascalTriangle2(int row){
    for(int i = 1 ; i<=row ; i++){
        generaterow(i);
        cout<<endl;
    }
}

int main(){
    int row;
    cin>>row;

    // vector<vector<int>> ans = pascalTriangle(row);

    // for(int i = 0 ; i<row; i++){
    //     for(int j = 0 ; j<ans[i].size() ; j++){
    //         cout<<ans[i][j]<<" ";
    //     }

    //     cout<<endl;
    // }

    pascalTriangle2(row);

    return 0;
}