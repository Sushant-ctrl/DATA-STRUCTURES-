#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
struct Node
{
	int data;
	struct Node *next;
};


struct Node* append(struct Node* head, int newnumber, int position)
{
	struct Node* current = NULL;
	struct Node* prev = NULL;
	prev = (struct Node*)malloc(sizeof(struct Node));
	current = (struct Node*)malloc(sizeof(struct Node));
	
	current = head;
	prev = current;
	int i;
	for(i= 0; i < position ; i++)
	{
		prev = current;
		current = prev -> next;
	}
	
	struct Node* insertion = NULL;
	insertion = (struct Node*)malloc(sizeof(struct Node));
	
	insertion -> data = newnumber;
	insertion -> next = current;
	prev -> next = insertion;

	return head;
}

struct Node* divide(struct Node *n)
{
	struct Node *half = (struct Node*)malloc(sizeof(struct Node));
	struct Node *prev = (struct Node*)malloc(sizeof(struct Node));
	half = n;
	prev = half;
	int i;
	i=0;
	while (n!= NULL)
	{
		i++;
		if (i>=3 && i%2==0)
		{
			prev = half;
			half = half -> next;
		}
		n = n -> next;
	}
	prev = prev -> next;
	half = half->next;
	prev->next =NULL;
	return half;
}

void print(struct Node* n)
{
	while (n!= NULL)
	{
		printf("%d\t",n->data);
		n = n->next;
	}
}

int main()
{
	struct Node* head = NULL;
	struct Node* second = NULL;
	struct Node* half = NULL;
	
	head = (struct Node*)malloc(sizeof(struct Node));
	second = (struct Node*)malloc(sizeof(struct Node));

	head -> data = 1;
	head -> next = second;
	
	second -> data = 2;
	second -> next = NULL;
	
	head = append(head , 5,1);
	head = append(head , 0,2);
	head = append(head , 15,1);
	//head = append(head , 125,1);
	printf("orignal list:");
	print(head);
	printf("\nFirst half:");
	half = divide (head);
	print(head);
	printf("\nSecond half");
	print(half);
}
