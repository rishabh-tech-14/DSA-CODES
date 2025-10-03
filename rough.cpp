#include<iostream>
#include<vector>
using namespace std;

class node{
    public:
        int data;
        node* next;

    public:
        node(int data1 , node* next1){
            data = data1;
            next = next1;
        }

        node(int data1){
            data = data1;
        }
};

node* convertarr2LL(vector<int> & arr){
    node* head = new node(arr[0]);
    node* mover = head;
    
    for(int i = 1 ; i<arr.size() ; i++){
        node* temp = new node(arr[i]);
        mover->next = temp;
        mover = temp;
    }

    return head;
}

int main(){
    vector<int> arr = {2,4,5,1,6,7,9};
    node* head = convertarr2LL(arr);
    node* temp = head;

    while(temp){
        cout<<temp->data<<" ";
        temp = temp->next;        
    }

    


    return 0;
}