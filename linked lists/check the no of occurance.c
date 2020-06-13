#include <stdio.h>
# include <stdlib.h>
# include <conio.h>

struct Node
{
	int data;
	struct Node *next;
};

int occur(struct Node *, int );
struct Node* append(struct Node*, int , int );
void print(struct Node *);

int occur(struct Node *n, int entry)
{
	int i;
	i=0;
	while (n!= NULL)
	{
		if (n -> data == entry)
		{
			i++;
		}
		n = n -> next;
	}
	return i;
}

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

void print(struct Node* n)
{
	while (n!= NULL)
	{
		printf("%d ",n->data);
		n = n -> next;
	}
}

int main()
{
	struct Node *head;
	struct Node *second;
	
	head = (struct Node*)malloc(sizeof(struct Node));
	second = (struct Node*)malloc(sizeof(struct Node));

	head -> data = 1;
	head -> next = second;
	
	second -> data = 2;
	second -> next = NULL;
	
	head = append(head , 5,1);
	head = append(head , 5,1);
	head = append(head , 5,2);
	head = append(head , 2,1);
	head = append(head , 0,2);
	head = append(head , 15,1);
	
	print(head);
	
	int occur_2, occur_15, occur_5;
	
	occur_2 = occur(head,2);
	occur_15 = occur(head,15);
	occur_5 = occur(head,5);
	
	printf("\n2 occurs %d times",occur_2);
	printf("\n15 occurs %d times",occur_15);
	printf("\n5 occurs %d times",occur_5);
}
