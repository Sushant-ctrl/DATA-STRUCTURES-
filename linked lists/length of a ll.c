#include <stdio.h>
# include <stdlib.h>
# include <conio.h>

struct Node
{
	int data;
	struct Node *next;
};

int length(struct Node *);

int length(struct Node *n)
{
	int i;
	i=0;
	while (n!= NULL)
	{
		i++;
		n = n -> next;
	}
	return i;
}

int main()
{
	struct Node* head = NULL;
	struct Node* second = NULL;
	
	head = (struct Node*)malloc(sizeof(struct Node));
	second = (struct Node*)malloc(sizeof(struct Node));

	head -> data = 1;
	head -> next = second;
	
	second -> data = 2;
	second -> next = NULL;
	
	int l;
	l = length(head);
	printf("%d",l);
	return 0;
}


