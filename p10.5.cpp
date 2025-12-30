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

node* add2NUmbers(node* head1 , node* head2){
    node* dummyHead = new node(-1);
    node* curr = dummyHead;

    int carry = 0;

    while(head1!=NULL || head2!=NULL){
        int sum = carry;

        if(head1) sum+=head1->data;
        if(head2) sum+=head2->data;

        node* newNode = new node(sum%10);
        carry = sum/10;

        curr->next = newNode;
        curr = curr->next;

        if(head1) head1 = head1->next;
        if(head2) head2 = head2->next;        
    }

    if(carry){
        node* newNode = new node(carry);
        curr->next = newNode;
    }

    return dummyHead->next;

}
int main()
{
    vector<int> num1 = {1, 2, 3, 4};
    vector<int> num2 = {5, 6, 7, 8};

    node *head1 = convertArr2LL(num1);
    node *head2 = convertArr2LL(num2);

    node *head3 = add2NUmbers(head1,head2);

    // print(head1);
    // print(head2);

    print(head3);    


    return 0;
}