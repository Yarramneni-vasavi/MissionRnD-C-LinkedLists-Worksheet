/*
OVERVIEW: Given a single linked list, remove every Kth node in the linked list.
E.g.: 1->2->3->4->5 and K 2, output is 1->3->5.

INPUTS: A linked list and Value of K.

OUTPUT: Remove every Kth node in the linked list.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>

struct node {
	int num;
	struct node *next;
};

int ListLength(struct node *temp);

struct node * removeEveryKthNode(struct node *head, int K) 
{
	if (K > 1 && head != NULL)
	{
		struct node *a;
		struct node *b;
		a = head;
		b = head;
		int len = ListLength(head);
		while (b != NULL)
		{
			for (int i = 0; i < K; i++)
			{
				if (b->next != NULL)
					b = b->next;
				if (K - i > 2)
					a = a->next;
				else if (b->next == NULL)
				{
					b = NULL;
					break;
				}
			}
			a->next = b;
			a = b;
			if (K > len / 2)
			{
				break;
			}
		}
		a = head;
		return a;
	}
	return NULL;
}

int ListLength(struct node *head)
{
	int length = 0;
	struct node *temp;
	temp = head;
	while (temp != NULL)
	{
		length ++;
		temp = temp->next;
	}
	return length;
}