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

int printarr(int arr[], int num)
{
	int i;
	for (i=0; i<num; i++)
	{
		printf("%d\t",arr[i]);
	}
	return num;
}

void print (struct Node* n, int arr[], int num)
{	
	if (n == NULL)
	{	
		return;
	}
	arr[num] = n->data;
	num++;
	//num = printarr(arr,num,end);
	if (n->left == NULL && n->right == NULL)
	{
		num = printarr(arr,num);
		printf("\n");
	}
 	else
	{	
		print(n->left,arr,num);
		print(n->right,arr,num);
	}
	
} 

int main ()
{
	struct Node* root = newNode(1);
	root -> left = newNode(2);
	root -> right = newNode(3);
	root -> left -> left = newNode(4);
	root -> left -> right = newNode(5);
	root -> right -> left = newNode(6);
	root -> right -> left -> right = newNode(7);
	int arr[1000],num = 0;
	print2D(root,0);
	print(root,arr,num);
	return 0;
	
}
