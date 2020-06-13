# include <stdio.h>
# include <stdlib.h>
# include <conio.h>

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

void lastm(struct Node *n, int m)
{
	int i,j;
	int arr[10];
	i=0;
	while (n!= NULL)
	{
		i++;
		arr[i] = n->data;
		n = n -> next;
	}
	if (m>i)
	m=i-1;
	for(j=i-m; j<=i; j++)
	{
		printf("%d\t",arr[j]);
	}
}

void printlist(struct Node* n)
{
	while (n!= NULL)
	{
		printf("%d ",n->data);
		n = n -> next;
	}
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
	
	head = append(head , 5,1);
	head = append(head , 0,2);
	head = append(head , 15,1);
	
	printlist(head);
	printf("\n");
	
	int m;
	printf("Enter the value of m:");
	scanf("%d",&m);
	printf("\n");
	lastm(head,m);
	return 0;
}


