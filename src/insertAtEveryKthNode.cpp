/*
OVERVIEW: Given a single linked list insert a new node at every Kth node with value K.
E.g.: 1->2->3->4->5, k = 2, 1->2->2->3->4->2->5

INPUTS: A linked list and Value of K.

OUTPUT: Insert a new node at every Kth node with value K.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>
#include <malloc.h>

struct node {
	int num;
	struct node *next;
};

struct node * insertAtEveryKthNode(struct node *head, int K) {
	int temp1;
	if (head == NULL || K < 0)return(NULL);
	if (head != NULL&&K>0){
		struct node *temp = head, *r;
		while (temp != NULL){
			temp1 = K;
			while (temp1 > 1){
				temp = temp->next;
				if (temp == NULL){
					return head;
				}
				temp1--;
			}
			r = (struct node*)malloc(sizeof(struct node));
			r->num = K;
			r->next = temp->next;
			temp->next = r;
			temp = r->next;

		}
		return head;
	}
	
}

