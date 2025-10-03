#include<iostream>
#include<vector>
using namespace std;

class node{
    public:
        int data;
        node* next;
    
    public:
        node(int val , node* next1){
            data = val;
            next = next1;
        }

        node(int val){
            data = val;
            next = nullptr;
        }
};

node* convertArr2LL(vector<int> &arr){
    node* head = new node(arr[0]);
    node* mover = head;

    for(int i = 1 ; i<=arr.size() ; i++){
        node* temp = new node(arr[i]);
        mover->next = temp;
        mover = temp;
    }

    return head;
}

void print(node* head){
    while(head!=NULL){
        if(head->next == NULL) break;
        cout<<head->data<<" ";
        head = head->next;        
    }
}

node* removesHead(node* head){
    if(head == NULL) return head;
    node* temp = head;
    head = head->next;
    free(temp);
    return head;
}

node* removesTail(node* head){
    if(head == NULL || head->next == NULL){
        return NULL;
    }

    node* temp = head;

    while(temp->next->next!=NULL){
        temp = temp->next;
    }

    free(temp);

    temp->next = nullptr;

    return head;
}

node* removeKele(node* head , int k){
    if(head == NULL ) return head;

    if(k==1){
        node* temp = head;
        head = head->next;
        free(temp);

        return head;
    }

    int cnt = 0;
    node* temp = head;
    node* prev = NULL;

    while(temp!=NULL){
        cnt++;

        if(cnt == k){
            prev->next = prev->next->next;
            free(temp);
            break;
        }

        prev = temp;
        temp = temp->next;
    }

    return head;
}

node* removeElement(node* head , int ele){
    if(head==NULL) return head;

    if(head->data == ele){
        node*temp = head;
        head = head->next;
        free(temp);
    }

    node* temp = head;
    node* prev = NULL;

    while(temp){
        if(temp->data == ele){
            prev->next =prev->next->next;
            free(temp);
            return head;
        }

        prev = temp;
        temp = temp->next;
    }

    return head;
}

int main(){
    vector<int> arr = {1,3,4,5,6,7,8};

    node* head = convertArr2LL(arr);
    node* temp = removeElement(head,9);
    print(temp);
    
    return 0;
}