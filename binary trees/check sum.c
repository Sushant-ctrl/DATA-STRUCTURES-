# include <stdio.h>
# include <stdlib.h>
#include<malloc.h> 
#define COUNT 5


struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
};

struct Node* newNode(int);

struct Node* newNode(int data)
{
	struct Node* node = (struct Node*)malloc(sizeof(struct Node));
	
	node -> data = data;
	node -> left = NULL;
	node -> right = NULL;
	return node;
}

void print2D(struct Node *root, int space) 
{ 
    if (root == NULL) 
        return; 
   
    space += COUNT; 
  
    print2D(root->right, space); 
    printf("\n"); 
 
 	int i;
	    
	for (i = COUNT; i < space; i++) 
        printf(" "); 
    
	printf("%d\n", root->data); 
  
    print2D(root->left, space); 
} 

int sum1(struct Node* n, int sum)
{

	if (n == NULL)
	{return 0;
	}
	
	if ((n->left == NULL )&& (n->right == NULL))
	{
		if (n->data == sum)
		{return 1;
		}
		else
		{return 0;
		}
		
	}
	if (sum1(n->left, (sum - n->data)))
	return 1;
	if (sum1(n->right, (sum - n->data)))
	return 1;
}

int main ()
{
	struct Node* root = newNode(1);
	root -> left = newNode(2);
	root -> right = newNode(3);
	root -> left -> left = newNode(4);
	root -> left -> right = newNode(5);
		int a;
	print2D(root,0);
	a = sum1 (root,89);
	if (a == 1)
	printf("Sum exists");
	else
	printf("Sum doesn't exist");
	return 0;
	
}
