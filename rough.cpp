#include<iostream>
#include<vector>
using namespace std;

class node{
    public:
        int data;
        node* next;
        node* prev;

    public: 
        node(int data1 , node* next1 , node* prev1){
            data = data1;
            next = next1;
            prev = prev1;
        }

        node(int data1){
            data = data1;
            next = nullptr;
            prev = nullptr;
        }
};

node* convertArr2DLL(vector<int> &arr){
    node* head = new node(arr[0]);
    node* prev = head;

    for(int i = 1 ; i<arr.size() ; i++){
        node* temp = new node(arr[i],nullptr,prev);
        prev->next = temp;
        prev = temp;
    }

    return head;
}

void print(node* head){
    node* temp = head;

    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}



int main(){
    vector<int> arr = {1,2,3,4,5,6,7,8,9};
    node* head = convertArr2DLL(arr);

    print(head);

    return 0;
}