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

node *convertArr2LL(vector<int> num1)
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
node* oddEvenList1(node* head){
    if(head == NULL || head->next == NULL){
        return head;
    }

    vector<int> arr;
    node* temp = head;

    while(temp!=NULL && temp->next!=NULL){
        arr.emplace_back(temp->data);
        temp = temp->next->next;
    }

    if(temp) arr.emplace_back(temp->data);
    temp = head->next;

    while(temp!=NULL && temp->next!=NULL){
        arr.emplace_back(temp->data);
        temp = temp->next->next;
    }

    if(temp) arr.emplace_back(temp->data);
    temp = head;

    int i = 0;

    while(temp){
        temp->data = arr[i++];
        temp = temp->next;
    }

    return head;
}

// OPTIMAL APPROACH
node* oddEvenList2(node* head){
    if(head == nullptr || head->next == nullptr){
        return head;
    }

    node* odd = head;
    node* even = head->next;
    node* evenHead = even;

    while(even!=NULL && even->next!=NULL){
        odd->next = odd->next->next;
        even->next = even->next->next;

        odd = odd->next;
        even = even->next;
    }

    odd->next = evenHead;

    return head;
}

int main(){
    vector<int> arr = {1,2,3,4,5,6,7,8,9};

    node *head1 = convertArr2LL(arr);

    node* head = oddEvenList2(head1);

    print(head);


    return 0;
}