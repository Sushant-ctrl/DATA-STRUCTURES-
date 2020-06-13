# include <stdio.h>
# include <stdlib.h>
# include <conio.h>

struct Node
{
	int data;
	struct Node *next;
};

void printlist(struct Node*);
struct Node* append(struct Node*, int, int);
struct Node* appendlists(struct Node*, struct Node*);

int main()
{
	struct Node* head1 = NULL;
	struct Node* head2 = NULL;
	struct Node* head3 = NULL;
	
	head1 = (struct Node*)malloc(sizeof(struct Node));
	head2 = (struct Node*)malloc(sizeof(struct Node));
	head3 = (struct Node*)malloc(sizeof(struct Node));

	head1 -> data = 1;
	head1 -> next = NULL;
	
	head2 -> data = 1;
	head2 -> next = NULL;
	
	printf("The list1 is: ");
	
	head1 = append(head1, 5,1);
	head1 = append(head1, 0,1);
	head1 = append(head1, 15,1);
	printlist(head1);
	
	printf("\nThe list2 is: ");
	head2 = append(head2, 3, 1);
	head2 = append(head2, 3, 1);
	head2 = append(head2, 3, 1);
	printlist(head2);
	
	head3 = appendlists(head1, head2);
	printf("\nThe combined list is:");
	printlist(head3);
	return 0;
} 

void printlist(struct Node* n)
{
	while (n!= NULL)
	{
		printf("%d ",n->data);
		n = n -> next;
	}
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

struct Node* appendlists(struct Node* head1, struct Node* head2)
{
	struct Node *n = NULL;
	n = (struct Node*)malloc(sizeof(struct Node));
	n = head1;
	
	int f = 0;
	
	while (f == 0)
	{
		if (n->next == NULL)
		{
		n -> next = head2;		
		f = 1;
		}
		n = n -> next;
	}
	return head1;
}
