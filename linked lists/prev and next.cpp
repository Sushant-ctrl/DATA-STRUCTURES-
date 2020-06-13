# include <stdio.h>
# include <stdlib.h>
# include <conio.h>

struct Node
{
	int data;
	struct Node *next;
};

void previous(struct Node*);
struct Node* append(struct Node*, int, int);

void print(struct Node* n)
{
	while(n!= NULL)
	{
		printf("%d\t",n->data);
		n = n->next;
	}
}

struct Node* previous(struct Node* head,struct Node* n)
{
	struct Node* prev = (struct Node*)malloc(sizeof(struct Node));
	while (head != NULL)
	{
		prev = head;
		head = head -> next;
		if (head == n)
		{
			return prev;
		}
	}
}

struct Node* next(struct Node* n)
{
	return n->next;
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

int main()
{
	struct Node* head = NULL;
	struct Node* second = NULL;
	struct Node* third = NULL;
	
	head = (struct Node*)malloc(sizeof(struct Node));
	second = (struct Node*)malloc(sizeof(struct Node));
	third = (struct Node*)malloc(sizeof(struct Node));
	
	head -> data = 1;
	head -> next = second;
	
	second -> data = 2;
	second -> next = third;
	
	third -> data = 3;
	third -> next = NULL;
	printf("The list is: ");
	
	head = append(head , 5,1);
	head = append(head , 0,1);
	head = append(head , 15,1);
	print(head);
	
	struct Node* prev = NULL;
	struct Node* nxt = NULL;
	
	prev = previous(head, second);
	nxt = next(second);
	printf("\nThe current node is %d",second->data);
	printf("\nThe previous node is %d",prev->data);
	printf("\nThe next node is %d",nxt->data);
	return 0;
} 
