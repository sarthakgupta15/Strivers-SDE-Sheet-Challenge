#include <iostream> 
using namespace std;


//Following is the class structure of the LinkedListNode class:

    template <typename T>
    class LinkedListNode
    {
    public:
        T data;
        LinkedListNode<T> *next;
        LinkedListNode(T data)
        {
            this->data = data;
            this->next = NULL;
        }
    };



void deleteNode(LinkedListNode<int> * node) {
    // Write your code here.
    //create a temp pointer that initially 
    LinkedListNode<int> *temp = node->next;
    //Store the data of temp as node->data and make node->next = temp->next
    node->data = temp->data;
    node->next = temp->next;
    delete temp;
}

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 
class Solution {
public:
    void deleteNode(ListNode* node) {
    // Since we know input node is not last node, so nextNode will not be null
        ListNode *nextNode = node->next;
        // Step 2
        node->val = nextNode->val;
        // Step 3
        node->next = nextNode->next;
        nextNode->next = nullptr;
        delete(nextNode);
    }
};
**/