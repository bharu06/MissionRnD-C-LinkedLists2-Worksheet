/*
OVERVIEW: Merge two sorted linked lists.
E.g.: 1->3->5 and 2->4, output is 1->2->3->4->5.

INPUTS: Two sorted linked lists.

OUTPUT: Return merged sorted linked list.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>

struct node {
	int num;
	struct node *next;
};

struct node * merge2LinkedLists(struct node *head1, struct node *head2) {
	if (head1 == NULL && head2 == NULL) {
		return NULL;
	}
	else if (head1 == NULL) {
		return head2;
	}
	else if (head2 == NULL) {
		return head1;
	}
	struct node *head = NULL;
	struct node *temp1 = head1;
	struct node *temp2 = head2;
	if (head1->num <= head2->num) {
		head = head1;
		temp1 = temp1->next;
	}
	else {
		head = head2;
		temp2 = temp2->next;
	}
	struct node *temp = head;
	while (temp1 != NULL && temp2 != NULL) {
		if (temp1->num < temp2->num) {
			// increment temp1
			temp->next = temp1;
			temp = temp->next;
			temp1 = temp1->next;
		}
		else if (temp1->num > temp2->num) {
			// increment temp2
			temp->next = temp2;
			temp = temp->next;
			temp2 = temp2->next;
		}
		else {
			// increment both
			temp->next = temp1;
			temp = temp->next;
			temp1 = temp1->next;
			temp->next = temp2;
			temp = temp->next;
			temp2 = temp2->next;
		}
	}
	while (temp1 != NULL) {
		temp->next = temp1;
		temp = temp->next;
		temp1 = temp1->next;
	}
	while (temp2 != NULL) {
		temp->next = temp2;
		temp = temp->next;
		temp2 = temp2->next;
	}
	return head;
}