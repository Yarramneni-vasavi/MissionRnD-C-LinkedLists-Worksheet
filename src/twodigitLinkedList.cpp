/*
OVERVIEW:  Given a single linked list (two digits as a node).Convert that to number


INPUTS:  SLL head pointer

OUTPUT: Create a number from the linked list given ,In each node there are two numbers ,digit1 and digit1 ,
So if the nodes are 12->34->56->78 , Final number would be 12345678 ( Integer)

ERROR CASES:

NOTES: Only Postive Numbers
*/

#include <stdio.h>
#include <malloc.h>

struct node {
	int digit1;
	int digit2;
	struct node *next;
};

long int power(int base, int exp);
int CountLength(struct node *temp);

int convert_sll_2digit_to_int(struct node *head)
{
	int len = CountLength(head);
	long int N = 0;
	//separating integers from node
	while (head->next != NULL)
	{
		N = N + ((head->digit1)*power(10, len)) + ((head->digit2)*power(10, len - 1));
		len = len - 2;
		head = head->next;
	}
	N = N + ((head->digit1) * 10) + (head->digit2);
	return N;
}

long int power(int base, int exp)
{
	for (int i = 1; i < exp; i++)
	{
		base = base * 10;
	}
	return base;
}

int CountLength(struct node *head)
{
	int length = 0;
	struct node *temp;
	temp = head;
	while (temp != NULL)
	{
		length += 2;
		temp = temp->next;
	}
	return length - 1;
}
