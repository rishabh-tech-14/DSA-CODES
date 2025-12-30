#include<iostream>
#include<vector>
#include<stack>
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

// BRUTE-FORCE APPROACH
node* reverseDLL1(node* head){
    if(head==NULL || head->next==NULL){
        return head;
        node* temp = head;        
    }

    node* temp = head;
    stack<int> st;

    while(temp!=NULL){
        st.emplace(temp->data);
        temp=temp->next;
    }

    temp = head;

    while(temp!=NULL){
        temp->data = st.top();
        st.pop();
        temp=temp->next;
    }

    return head;
}

// OPTIMAL APPROACH
node* reverseDLL2(node* head){
    if(head==nullptr || head->next==nullptr){
        return head;
    }

    node* curr = head;

    while(curr!=NULL){
        node* temp = curr->next;
        curr->next = curr->back;
        curr->back = temp;

        head = curr;
        curr = temp;
    }

    return head;
}

int main(){
    vector<int> arr = {1,2,3,4,5,6,7,8,9};

    node* head1 = convertArr2DLL(arr);

    node* head = reverseDLL2(head1);

    print(head);
}