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

static struct Node *prev = NULL; 

int bst(struct Node* node)
{
    if (node)
    {
        if (!bst(node->left)) 
            return 0;
        if (prev != NULL && node->data <= prev->data)
            return 0;
        prev = node;
        return bst(node->right); 
    }
    return 1;
}

int main ()
{
	struct Node* root = newNode(7);
	/*root -> left = newNode(5);
	root -> right = newNode(10);
	root -> left -> left = newNode(4);
	root -> left -> right = newNode(6);
	root -> right -> right = newNode(12);
	root -> right -> left = newNode(9);
	*/
	printf("Tree =========================================================================");
	print2D(root,0);
	
	int flag;
	flag = bst (root);
	if (flag == 1)
	printf("the tree is bst.");
	else
	printf("The tree isn't bst");
	return 0;
	
}
