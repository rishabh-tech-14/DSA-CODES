#include<iostream>
#include<vector>
using namespace std;

class node{
    public:
        int data;
        node* next;
        node* back;

    public:
        node(int data1 , node* next1 , node*back1){
            data = data1;
            next = next1;
            back = back1;
        }

        node(int data1){
            data = data1;
            next = nullptr;
            back = nullptr;
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
        temp = temp->next;
    }
}

node* insertBeforeHead(node* head , int val){
    node* newHead = new node(val,head,nullptr);
    head->back = newHead;

    return newHead;
}

node* insertBeforeTail(node* head , int val){
    if(head->next==NULL){
        node* newHead = new node(val,head,nullptr);
        head->back = newHead;

        return newHead;
    }

    node* temp = head;

    while(temp->next!=NULL){
        temp = temp->next;
    }

    node* prev = temp->back;

    node* newNode = new node(val,temp,prev);

    prev->next = newNode;
    temp->back = newNode;

    return head;
}

node* insertBeforeKthEle(node* head , int k , int val){
    if(k==1){
        node* newHead = new node(val,head,nullptr);
        head->back = newHead;

        return newHead;
    }

    node* temp = head;
    int cnt = 0;

    while(temp!=NULL){
        cnt++;

        if(cnt==k) break;

        temp = temp->next;
    }

    node* prev = temp->back;

    node* newNode = new node(val,temp,prev);
    prev->next = newNode;
    temp->back = newNode;

    return head;
}

node* insertBeforeNode(node* head ,node* Node , int val){
    node* prev = Node->back;

    node* newNode = new node(val,Node,prev);
    prev->next = newNode;
    Node->back = newNode;

    return head;
}

int main(){
    vector<int> arr = {1,2,3,4,5,6,7,8};

    node* head1 = convertArr2DLL(arr);

    node* head = insertBeforeNode(head1,head1->next->next,99);

    print(head);

    return 0;
}