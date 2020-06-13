# include <stdio.h>
# include <stdlib.h>
#include<malloc.h> 
# define COUNT 5


struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
};

struct Node* newNode(int);
void print2D(struct Node *, int); 

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

int identical(struct Node* node1, struct Node* node2)
{
	if (node1 == NULL && node2 == NULL)
	{
		return 1;
	}
	else if (node1 != NULL && node2 != NULL)
	{
		return identical(node1 -> left, node2 -> left);
		return identical(node1 -> right, node2 -> right);
	}
	else
	{
		return 0;
	}
}

int main ()
{
	struct Node* root1 = newNode(1);
	root1 -> left = newNode(20);
	root1 -> right = newNode(3);
	root1 -> left -> left = newNode(4);
	root1 -> left -> right = newNode(5);
	
	struct Node* root2 = newNode(1);
	root2 -> left = newNode(2);
	root2 -> right = newNode(3);
	root2 -> left -> left = newNode(4);
	root2 -> left -> left -> left = newNode(5);
	
	printf("Tree 1 =========================================================================");
	print2D(root1,0);
	printf("Tree 2 =========================================================================");
	print2D(root2,0);
	
	int flag;
	flag = identical (root1, root2);
	if (flag == 1)
	printf("the two trees are structurally identical.");
	else
	printf("The two trees aren't structurally identical");
	return 0;
	
}
