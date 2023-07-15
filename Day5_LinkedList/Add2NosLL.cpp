#include<iostream>
using namespace std;

/*
    Time Complexity: O('m' + 'n')
    Space Complexity: O(Max('m', 'n'))

    Where 'm' and 'n' are the lengths of the linked lists.
*/

//Definition of linked list:
 
class Node {
    public:
    int data;
    Node *next;
    Node() {
        this->data = 0;
        this->next = NULL;
    }
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
    Node (int data, Node *next) {
        this->data = data;
        this->next = next;
    }
};

Node *addTwoNumbersHelper(Node *node1, Node *node2, int carry)
{
    if (node1 == NULL && node2 == NULL && carry == 0)
    {
        // Added both the lists and no carry is generated.
        return NULL;
    }

    // 'val1' and 'val2' store the data of the current nodes of the two linked lists.
    int val1, val2;

    // 'next1' and 'next2' point to the node present after the current nodes of the two linked lists.
    Node *next1, *next2;

    if (node1 == NULL)
    {
        // List 1 is empty. So, consider the current node's value as zero.
        val1 = 0;
        // And the node after the current node as NULL.
        next1 = NULL;
    }
    else
    {
        val1 = node1->data;
        next1 = node1->next;
    }

    if (node2 == NULL)
    {
        // List 2 is empty. So, consider the current node's value as zero.
        val2 = 0;
        // And the node after the current node as NULL.
        next2 = NULL;
    }
    else
    {
        val2 = node2->data;
        next2 = node2->next;
    }

    // Add the values in the current nodes along with the carry.
    int sum = val1 + val2 + carry;

    // Create the next node of the sum list.
    Node *sumNode = new Node(sum % 10);

    // Recursively call the function to generate the remaining nodes of the sum list.
    sumNode->next = addTwoNumbersHelper(next1, next2, sum / 10);

    return sumNode;
}

Node *addTwoNumbers(Node *num1, Node *num2)
{
    return addTwoNumbersHelper(num1, num2, 0);
}
