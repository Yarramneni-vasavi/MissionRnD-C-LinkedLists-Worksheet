/*
OVERVIEW: Given an unsorted single linked list, sort the linked list without using extra array or linked list.
E.g.: 4->2->1->5->3, output is 1->2->3->4->5.

INPUTS: An unsorted single linked list.

OUTPUT: Sort the linked list.

ERROR CASES: Return NULL for error cases.

NOTES: Without using extra array or linked list.
*/

#include <stdio.h>

struct node {
	int num;
	struct node *next;
};

struct node * SortandMerged(struct node *a, struct node *b);
void Sort(struct node **head);

struct node * sortLinkedList(struct node *head) 
{
	if (head != NULL)
	{
		Sort(&head);
		return head;
	}
	return NULL;
}

void Sort(struct node **head)
{
	struct node *head_ptr = *head;
	struct node *a;
	struct node *b;

	if (head_ptr->next == NULL)
		return;

	a = head_ptr;
	b = head_ptr->next;
	while (b != NULL)
	{
		b = b->next;
		if (b != NULL)
		{
			a = a->next;
			b = b->next;
		}
	}
	b = a->next;
	a->next = NULL;
	a = head_ptr;

	Sort(&a);
	Sort(&b);
	*head = SortandMerged(a, b);
}

struct node * SortandMerged(struct node *a, struct node *b)
{
	struct node *finalMergedList = NULL;
	if (a == NULL)
	{
		return b;
	}
	else if (b == NULL)
	{
		return a;
	}
	if (a->num <= b->num)
	{
		finalMergedList = a;
		finalMergedList->next = SortandMerged(a->next, b);
	}
	else
	{
		finalMergedList = b;
		finalMergedList->next = SortandMerged(a, b->next);
	}
	return finalMergedList;
}