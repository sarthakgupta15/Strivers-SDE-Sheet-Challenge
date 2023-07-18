#include<iostream>
using namespace std;

//Definition for singly-linked list.
class Node {
public:
    int data;
    Node *next;
    Node() : data(0), next(nullptr) {}
    Node(int x) : data(x), next(nullptr) {}
    Node(int x, Node *next) : data(x), next(next) {}
};
 
//Circular LL Approach
Node *rotate(Node *head, int k) {
     if(head==NULL){
          return head;
     }
     int len=1;
     Node *temp=head;
     //calculate length of the ll.
     while(temp->next!=NULL){
          temp = temp->next;
          len++;
     }
     //if k>len eg.k=12 and len=5 then k%len=2
     k = k%len;
     //if no. of rotations are same as len so no change
     if(k==len || k==0){
          return head;
     }
     //To make a circular ll. Last node->next=head
     temp->next = head;
     temp=head;
     for(int i=0; i<abs(len-k-1);i++){
          temp = temp->next; //move temp to len-k. prev node of temp. and point it to null and make temp as head
     }
     head = temp->next;
     temp->next = NULL;
     return head;
}