#include<iostream>
#include<unordered_set>
using namespace std;

//    Following is the class structure of the Node class:

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

//Look up Hash Table
Node *firstNode(Node *head)
{
    //    Write your code here.
    unordered_set<Node *>nodesSeen;
    while(head!=NULL)
    {
        if(nodesSeen.count(head))
        {
            return head;
        }
        else
        {
            nodesSeen.insert(head);
        }
        head = head->next;
    }
    return NULL;
}