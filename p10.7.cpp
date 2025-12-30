#include <iostream>
#include <vector>
using namespace std;

class node
{
public:
    int data;
    node *next;

public:
    node(int data1, node *next1)
    {
        data = data1;
        next = next1;
    }

    node(int data1)
    {
        data = data1;
        next = nullptr;
    }
};

node *convertArr2LL(vector<int> &num1)
{
    node *head = new node(num1[0]);
    node *temp = head;

    for (int i = 1; i < num1.size(); i++)
    {
        node *curr = new node(num1[i]);
        temp->next = curr;
        temp = curr;
    }

    return head;
}

void print(node *head)
{
    node *temp = head;

    while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

// BRUTE-FORCE APPROACH
node* sortLL1(node* head){
    if(head == NULL || head->next == NULL){
        return head;
    }

    int count0 = 0;
    int count1 = 0;
    int count2 = 0;

    node* temp = head;

    while(temp!=NULL){
        if(temp->data==0) count0++;

        else if(temp->data==1) count1++;

        else count2++;

        temp = temp->next;
    }

    temp = head;

    while(count0){
        temp->data = 0;
        count0--;
        temp = temp->next;
    }

    while(count1){
        temp->data = 1;
        count1--;
        temp = temp->next;
    }

    while(count2){
        temp->data = 2;
        count2--;
        temp = temp->next;
    }

    return head;
}

// OPTIMAL APPROACH
node*sortLL2(node* head){
    if(head==NULL) return head;

    node* zeroHead = new node(-1);
    node* oneHead = new node(-1);
    node* twoHead = new node(-1);

    node* zeroTail = zeroHead;
    node* oneTail = oneHead;
    node* twoTail = twoHead;
    
    node* temp = head;

    while(temp!=NULL){
        int value = temp->data;

        if(value==0){
            zeroTail->next = temp;
            zeroTail = temp;
        }

        else if(value==1){
            oneTail->next = temp;
            oneTail = temp;
        }

        else{
            twoTail->next = temp;
            twoTail = temp;
        }

        temp = temp->next;
    }

    if(oneHead->next!=NULL){
        zeroTail->next = oneHead->next;
    }
    else zeroTail->next = twoHead->next;

    oneTail->next = twoHead->next;

    twoTail->next = nullptr;

    node* newHead = zeroHead->next;

    delete zeroHead;
    delete oneHead;
    delete twoHead;

    return newHead;
}

int main(){
    vector<int> arr = {2,1,2,2,0,1,0,0,0,1,2,1,0};

    node* head1 = convertArr2LL(arr);

    node* head = sortLL2(head1);

    print(head);

    return 0;
}