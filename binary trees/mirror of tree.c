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
void print2D(struct Node *, int ); 

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

void mirror(struct Node* node)
{
	if (node == NULL)
	{
		return;
    }
	else
	{
		mirror(node -> left);
		mirror(node -> right);
		
		struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
		
		temp = node -> left;
		node -> left = node -> right;
		node -> right = temp;
	}
	
}

int main ()
{
	struct Node* root = newNode(1);
	root -> left = newNode(2);
	root -> right = newNode(3);
	root -> left -> left = newNode(4);
	root -> left -> right = newNode(5);
	
	printf("Orignal tree ==========================================================================");
	print2D(root,0);
	
	mirror(root);
	
	printf("Mirror image of tree ==================================================================");
	print2D(root,0);
	return 0;
	
}
