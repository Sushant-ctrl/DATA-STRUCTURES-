#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

struct Node
{
	int data;
	struct Node* next;
};

void append(struct Node* n,int value)
{
	struct Node* node = (struct Node*)malloc(sizeof(struct Node));
	node -> data = value;
	node -> next = NULL;
	while(n->next != NULL)
	{
		n = n->next;
	}
	n -> next = node;
}

void print(struct Node *n)
{
	while(n != NULL)
	{
		printf("%d\t",n->data);
		n = n->next;
	}
}

struct Node* merge_sort(struct Node* n1, struct Node* n2)
{
	struct Node* n3 = (struct Node*)malloc(sizeof(struct Node));
	
	if (n1->data>n2->data)
	{
		n3->data = n2->data;
		n2 = n2->next;
	}
	else
	{
		n3->data = n1->data;
		n1 = n1->next;
	}
	n3 -> next = NULL;
	
	while(n1!=NULL || n2!=NULL)
	{
		if (n1!=NULL && n2!= NULL)
		{	
			if (n2->data>n1->data)
			{
				append(n3,n1->data);
				n1 = n1 -> next;
			}
			else
			{
				append(n3,n2->data);
				n2 = n2->next;
			}
		}
		else if(n1== NULL)
		{
			append(n3,n2->data);
			n2 = n2->next;
		}
		else if(n2==NULL)
		{
			append(n3,n1->data);
			n1 = n1 -> next;
		}
	}
	return n3;
}


void main()
{
	struct Node* head1 = NULL;
	struct Node* head2 = NULL;
	
	head1 = (struct Node*)malloc(sizeof(struct Node));
	head2 = (struct Node*)malloc(sizeof(struct Node));
	
	head1->data = -1;
	head1->next = NULL;
	head2->data = 0;
	head2->next = NULL;
	
	append(head1,1);
	append(head1,3);
	append(head1,4);
	append(head1,5);
	append(head1,28);
	
	append(head2,6);
	append(head2,8);
	append(head2,9);
	append(head2,13);
	append(head2,19);
	append(head2,100);
	
	printf("ll1: ");
	print(head1);
	printf("\n");
	printf("ll2: ");
	print(head2);
	
	struct Node* head3 = (struct Node*)malloc(sizeof(struct Node));
	head3 = merge_sort(head1, head2);
	printf("\n");
	printf("ll3: ");
	print(head3);
}
