#include <iostream>
using namespace std;

//Following is the class structure of the Node class:

        class Node
        {
        public:
	        int data;
	        Node *next;
	        Node(int data)
	        {
		        this->data = data;
		        this->next = NULL;
	        }
        };


Node *reverseKElements(Node *head, int n, int b[],int idx){
	//Base case List is empty or entire block array have been considered.
	if(head==NULL || idx>=n){
		return head;
	}
	//k will be the size of the current block
	int K = b[idx];
	//just move to the next block if size of the current block is zero
	if(K==0){
		return reverseKElements(head,n,b,idx+1);
	}
	Node *cur = head, *prev = NULL, *ahead = NULL;
	//no. of nodes reversed in the current block.
	int cnt = 0;
	//Reverse nodes until end of list is reached or current block has been reversed.
	while(cur!=NULL && cnt<K){
		ahead = cur->next;
		cnt++;
		cur->next = prev;
		prev = cur;
		cur = ahead;
	}
	//Reverse the next block
	head->next = reverseKElements(ahead, n, b, idx+1);
	return prev;
}

Node *getListAfterReverseOperation(Node *head, int n, int b[]){
	//if ll is empty return head of the ll
	if(head==NULL){
		return NULL;
	}
	//calling reverseKElements function to modify the given ll.
	head = reverseKElements(head, n, b, 0);
	return head;
}