# include <stdio.h>
# include <conio.h>

struct Node
{
	int data;
	struct Node *next;
};

void printlist(struct Node*);
struct Node* append(struct Node*, int, int);

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
	
	printf("The list is: ");
	
	head = append(head , 5,1);
	head = append(head , 0,3);
	head = append(head , 15,1);
	printlist(head);
	
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
