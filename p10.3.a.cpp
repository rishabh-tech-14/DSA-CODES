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

node* convertArr2DLL(vector<int> arr){
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

    while(head != NULL){
        cout<<head->data<<" ";
        head = head->next;
    }
}

node* deleteHead(node* head){
    if(head == NULL || head->next == NULL){
        return NULL;
    }

    node* prev = head;
    head = head->next;
    head->prev = nullptr;
    prev->next = nullptr;

    return head;
}

node* deleteTail(node* head){
    if(head==NULL) return head;

    if(head->next==NULL){
        delete head;
        return NULL;
    }

    node* temp = head;

    while(temp->next != NULL){
        temp = temp->next;
    }

    temp->prev->next = nullptr;
    free(temp);

    return head;
}

node* removeKele(node* head , int k){
    if(head==NULL) return head;

    int cnt;

    node* temp = head;

    while(temp!=NULL){
        cnt++;
        if(cnt==k) break;

        temp=temp->next;
    }

    node* back = temp->prev;
    node* front = temp->next;

    if(back==NULL || front==NULL) return NULL;

    if(back==NULL){
        deleteHead(head);
        return;
    }

    if(front==NULL){
        deleteTail(head);
        return;
    }

    back->next = front;
    front->prev = back;

    temp->next = nullptr;
    temp->prev = nullptr;

    delete temp;

    return head;
}



int main(){
    vector<int> arr = {1,2,3,4,5,6,7,8,99};

    node* head1 = convertArr2DLL(arr);

    node* head = deleteTail(head1);

    print(head);


    return 0;
}