/*
OVERVIEW:  Given a single linked list of 0s 1s and 2s ,Sort the SLL such that zeroes 
will be followed by ones and then twos.


INPUTS:  SLL head pointer

OUTPUT: Sorted SLL ,Head should Finally point to an sll of sorted 0,1,2


ERROR CASES:

NOTES: Only 0,1,2, will be in sll nodes
*/

#include <stdio.h>
#include <malloc.h>

struct node {
	int data;
	struct node *next;
};

struct node * Sort_and_Merge(struct node *a, struct node *b);
void MergeSort(struct node **head);

void sll_012_sort(struct node *head)
{
	if (head != NULL)
	{
		struct node *temp = head->next;
		MergeSort(&temp);
		int a = head->data;
		head->data = temp->data;
		head->next = temp;
		temp->data = a;
		while (temp->next != NULL)
		{
			if (temp->data > temp->next->data)
			{
				int temp_var = temp->data;
				temp->data = temp->next->data;
				temp->next->data = temp_var;
			}
			temp = temp->next;
		}
	}
}

void MergeSort(struct node **head)
{
	//using merge sort technique
	struct node *head_ptr = *head;
	struct node *a;
	struct node *b;

	if (head_ptr == NULL || head_ptr->next == NULL)
	{
		return;
	}

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

	MergeSort(&a);
	MergeSort(&b);
	*head = Sort_and_Merge(a, b);
}

struct node * Sort_and_Merge(struct node *a, struct node *b)
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
	if (a->data <= b->data)
	{
		finalMergedList = a;
		finalMergedList->next = Sort_and_Merge(a->next, b);
	}
	else
	{
		finalMergedList = b;
		finalMergedList->next = Sort_and_Merge(a, b->next);
	}
	return finalMergedList;
}