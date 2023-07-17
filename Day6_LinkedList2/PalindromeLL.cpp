#include <iostream> 
#include<stack>
using namespace std;

// Following is the class structure of the LinkedListNode class:
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

bool isPalindrome(LinkedListNode<int> *head) {
    // Write your code here.
    stack<int> st;
    LinkedListNode<int> *temp = head;
    while(temp!=NULL){
        st.push(temp->data);
        temp = temp->next;
    }
    while(head!=NULL){
        int top = st.top();
        st.pop();
        if(top!=head->data){
            return false;
        }
        head = head->next;
    }
    return true;
}

/*
Clone ll 
//    Time Complexity: O(N)
//  Space Compexity: O(N)

//  Where N is the total nodes in Linked List.

bool isPalindrome(LinkedListNode<int> *head) {

    // Creating a temporary node.
    LinkedListNode<int> *temp = head;

    // Creating Node for storing head of clone LinkedList.
    LinkedListNode<int> *cloneHead = NULL;

    while (temp != NULL) {

        LinkedListNode<int> *newNode = new LinkedListNode<int>(temp->data);

        newNode->next = cloneHead;

        cloneHead = newNode;

        temp = temp->next;

    }

    // Iterating clone and given Linked List.
    while (head != NULL) {

        // Check if both node value is same or not.
        if (head->data != cloneHead->data) {
            return false;
        }

        head = head->next;
        cloneHead = cloneHead->next;

    }

    return true;

}
*/


/* Recursion

    //Time Complexity: O(N)
    //Space Compexity: O(N)

    //Where N is the total nodes in Linked List.


bool isPalindromeUtil(LinkedListNode<int> *right, LinkedListNode<int> **left) {

    // Stop recursion when right reach end of LinkedList.
    if (right == NULL) {
        return true;
    }

    bool isPal = isPalindromeUtil(right->next, left);

    
    //    If sub-list is not palindrome then no need to check for current left and
    //    right, return false.
    

    if (!isPal) {
        return false;
    }

    // Check if both left and right node value are same.
    bool isSame = ((*left)->data == right->data) ? true : false;

    // Move left pointer to next node.
    *left = (*left)->next;
    return isSame;

}

bool isPalindrome(LinkedListNode<int> *head) {

    // Assign left node as start of LinkedList.
    LinkedListNode<int> *left = head;

    // Check if LinkedList is palindrome or not.
    bool isPal = isPalindromeUtil(head, &left);

    return isPal;

}

*/


/* Reversing the 2nd half


//    Time Complexity: O(N)
//    Space Compexity: O(1)

//    Where N is the total nodes in Linked List.


LinkedListNode<int> *reverse(LinkedListNode<int> *head) {

    // Creating node for remembering previous node in Linked List.
    LinkedListNode<int> *reverseHead = NULL;

    // Creating temporory node.
    LinkedListNode<int> *current = head;

    while (current != NULL) {

        LinkedListNode<int> *currentNext = current->next;
        current->next = reverseHead;
        reverseHead = current;
        current = currentNext;

    }

    // Return reverse Linked List.
    return reverseHead;

}

bool isPalindrome(LinkedListNode<int> *head) {

    LinkedListNode<int> *slow = head;
    LinkedListNode<int> *fast = head;
    LinkedListNode<int> *prev = head;

    // Find the middle node using TORTOISE-HARE-APPROACH.
    while (fast != NULL && fast->next != NULL) {
        prev = slow;
        fast = fast->next->next;
        slow = slow->next;
    }

    
    //    Fast pointer would become NULL when there are even elements in the list and
    //    not NULL for odd elements. We need to skip the middle node for odd case.
    
    if (fast != NULL) {
        slow = slow->next;
    }

    // When there is only one node in given Linked List.
    if (slow == NULL) {
        return true;
    }

    // Dividing Linked LIst in two part by pointing prev next to NULL.
    prev->next = NULL;

    // Now reverse the second half.
    LinkedListNode<int> *reverseHead = reverse(slow);

    // Iterate through both LinkedList and then compare it.
    while (head != NULL) {

        if (head->data != reverseHead->data) {
            return false;
        }
        reverseHead = reverseHead->next;
        head = head->next;

    }

    return true;

}
*/