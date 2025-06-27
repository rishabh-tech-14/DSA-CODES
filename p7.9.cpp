#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
using namespace std;

// BRUTE-FORCE APPROACH
int cntStudents1(vector<int> books , int pages){
    int n = books.size();
    int stu = 1;
    int pagesCnt = 0;

    for(int i = 0 ; i<n ; i++){
        if(pagesCnt+books[i]<=pages){
            pagesCnt += books[i];
        }
        else{
            stu++;
            pagesCnt = books[i];
        }
    }

    return stu;
}
int bookAllocation1(vector<int> books , int students){
    int n = books.size();

    if(students>n) return -1;

    int low=*max_element(books.begin(),books.end());
    int high = accumulate(books.begin(),books.end(),0);

    for(int i = low ; i<=high ; i++){
        if(cntStudents1(books,i)==students){
            return i;
        }
        else continue;
    }
}

// OPTIMAL APPROACH
int cntStudents2(vector<int> books , int pages){
    int n = books.size();
    int stu = 1;
    int pagesCnt = 0;

    for(int i = 0 ; i<n ; i++){
        if(pagesCnt+books[i]<=pages){
            pagesCnt += books[i];
        }
        else{
            stu++;
            pagesCnt = books[i];
        }
    }

    return stu;
}
int bookAllocation2(vector<int> books , int students){
    int n = books.size();
    int low = *max_element(books.begin(),books.end());
    int high = accumulate(books.begin(),books.end(),0);

    while(low<=high){
        int mid = (low+high)/2;

        if(cntStudents2(books,mid)<=students){
            high=mid-1;
        }

        else low=mid+1;
    }

    return low;
}

int main(){
    vector<int> books = {25,46,28,49,24};
    int m=4;

    cout<<bookAllocation2(books,m);

    return 0;
}