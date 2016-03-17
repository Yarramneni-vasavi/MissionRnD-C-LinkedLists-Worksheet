/*
OVERVIEW:  Given a number convert that to single linked list (each digit as a node).
E.g.: Input: 234, Output: 2->3->4.

INPUTS:  A number.

OUTPUT: Create linked list from given number, each digit as a node.

ERROR CASES: 

NOTES: For negative numbers ignore negative sign.
*/

#include <stdio.h>
#include <malloc.h>

struct node {
	int num;
	struct node *next;
};

struct node * insert_First(struct node *head, int data);

struct node * numberToLinkedList(int N) 
{
	struct node *head = NULL;
	int remainder;

	if (N < 0)
	{
		N = -N;
	}
	else if (N == 0)
	{
		head = insert_First(head, 0);
		return head;
	}

	while (N > 0)
	{
		remainder = N % 10;
		head = insert_First(head, remainder);
		N = N / 10;
	}
	return head;
}

struct node * insert_First(struct node *head, int data)
{
	struct node *temp;
	temp = (struct node*)malloc(sizeof(struct node));
	temp->num = data;
	temp->next = NULL;
	if (head == NULL)
	{
		head = temp;
	}
	else
	{
		temp->next = head;
		head = temp;
	}
	return head;
}