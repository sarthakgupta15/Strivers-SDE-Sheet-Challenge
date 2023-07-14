#include<iostream>
using namespace std;

/*
    Time Complexity : O(N)
    Space Complexity : O(1)

    where 'N' is the maximum length of linked list.
*/

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


int length(Node *head)
{
    int length = 0;
    Node *tmp = head;

    while (tmp != NULL)
    {
        tmp = tmp->next;
        length++;
    }

    return length;
}

Node* findIntersection(Node *firstHead, Node *secondHead)
{

    // Get the length of both list.
    int firstListLength = length(firstHead), secondListLength = length(secondHead);

    // Move headA and headB to the same start point.
    while (firstListLength > secondListLength)
    {
        firstHead = firstHead->next;
        firstListLength--;
    }

    while (firstListLength < secondListLength)
    {
        secondHead = secondHead->next;
        secondListLength--;
    }

    // Find the intersection until end.
    while (firstHead != secondHead)
    {
        firstHead = firstHead->next;
        secondHead = secondHead->next;
    }

    return firstHead;
}

/*
Hashing Approach

    Time Complexity : O(N + M)
    Space Complexity : O(N)

    where 'N' and 'M' are the lengths of the linked lists


#include <unordered_set>

Node* findIntersection(Node *firstHead, Node *secondHead)
{

    Node *firstHeadTmp = firstHead;

    // Set to store reference of first list.
    unordered_set<Node *> referenceSet;

    // Traverse the first list and store the reference in the set.
    while (firstHeadTmp != NULL)
    {
        referenceSet.insert(firstHeadTmp);
        firstHeadTmp = firstHeadTmp->next;
    }

    Node *secondHeadTmp = secondHead;

    // Traverse second list, check if the reference of current node is present or not.
    // If it is present then return that node.
    while (secondHeadTmp != NULL)
    {
        if (referenceSet.find(secondHeadTmp) != referenceSet.end())
        {
            return secondHeadTmp;
        }
        secondHeadTmp = secondHeadTmp->next;
    }

    return NULL;
}

*/

/*
Brute Force Approach

    Time Complexity : O(N * M)
    Space Complexity : O(1)

    where 'N' and 'M' are the lengths of the linked lists


Node* findIntersection(Node *firstHead, Node *secondHead)
{

    Node *firstHeadTmp = firstHead;

    // For every node of first list, traverse the second list and check if there is intersection.
    while (firstHeadTmp != NULL)
    {
        for (Node *secondHeadTmp = secondHead; secondHeadTmp != NULL; secondHeadTmp = secondHeadTmp->next)
        {
            if (firstHeadTmp == secondHeadTmp)
            {
                return firstHeadTmp;
            }
        }
        firstHeadTmp = firstHeadTmp->next;
    }

    // If there is no intersection, return NULL.
    return NULL;
}
*/