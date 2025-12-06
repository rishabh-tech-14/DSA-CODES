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
            next = nullptr;
        }
};

node* convert2LL(vector<int> &arr){
    node* head = new node(arr[0]);
    node* mover = head;

    for(int i = 1 ; i<arr.size() ; i++){
        node* temp = new node(arr[i]);
        mover->next = temp;
        mover = temp;
    }

    return head;
}

void print(node* head){
    while(head!=NULL){
        if(head == NULL) break;
        cout<<head->data<<" ";
        head = head->next;
    }
}

node* insertHead(node* head , int ele){
    node* temp = new node(ele , head);
    return temp;
}

node* insertAtTail(node* head , int ele){
    if(head == NULL) return new node(ele);

    node* temp = head;

    while(temp->next != NULL){
        temp = temp->next;
    }

    node* x = new node(ele);
    temp->next = x;

    return head;

}

node* insertAtPos(node* head , int ele , int k){
    if(head == NULL){
        if(k==1){
            return new node(ele);
        }
    }

    if(k==1){
        return new node(ele);
    }

    int cnt = 0 ;

    node* temp = head;

    while(temp!=NULL){
        cnt++;

        if(cnt==(k-1)){
            node* x = new node(ele);
            x->next = temp->next;
            temp->next = x;
            break;
        }

        temp = temp->next;
    }

    return head;

}

node* insertBeforeValue(node* head , int ele , int val){
    if(head == NULL) return head;

    if(head->data == val){
        return new node(ele, head);
    }

    node* temp = head;

    while(temp->next != NULL){
        if(temp->next->data == val){
            node* x = new node(ele , temp->next);
            temp->next = x;
            break;
        }
        temp = temp->next;
    }

    return head;
}

int main(){
    vector<int> arr = {2,3,5,6,7,9};

    node* head1 = convert2LL(arr);

    node* head = insertBeforeValue(head1,99,2);

    print(head);

    return 0;
}