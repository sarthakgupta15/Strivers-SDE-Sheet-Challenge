#include<iostream>
using namespace std;

//Following is the class structure of the Node class:

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data; 
        this->next = NULL;
    }
    Node(int data, Node* next)
    {
        this->data = data;
        this->next = next;
    }
};

Node* removeKthNode(Node* head, int K)
{
    // Write your code here.
    if(head==NULL || K==0){
        return head;
    }
    Node *slow=head;
    Node *fast=head;
    for(int i=0;i<K;i++){
        //if head is the kth node from end of ll.
        if(fast->next==NULL){
            Node *next = head->next;
            head->next = NULL;
            head = next;
            return head;
        }
        else{
            fast = fast->next;
        }
    }
    //Moving both slow and fast pointer with same speed
    while(fast->next!=NULL){
        slow = slow->next;
        fast = fast->next;
    }
    //Removing the kth node from end of linked list.
    slow->next = slow->next->next;
    
    return head;
}
