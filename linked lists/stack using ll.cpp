/* Immplementation of Stack Using Linked List */

#include<stdio.h>
#include<stdlib.h>


// Stack   [top]         linked list [top]->[element2]->[element3 (NULL)]
//		     |
//		[element2]
//		    |
//	   [element3]
//
typedef int listentry;
typedef struct node{
	listentry entry;
	node * next;
}Node;
typedef struct stack{
	Node* top;
}STACK;
void initialise_stack(STACK *s);
void push(STACK *s,listentry entry);
listentry pop(STACK *s);
int stack_empty(STACK *S);

int main(){
	int *k;
	k=(int * )malloc(sizeof(int));
	STACK *s;
	listentry i;
	s=(STACK *)malloc(sizeof(STACK));
	printf("Program Started");
	initialise_stack(s);
	i=1;
	printf("\n %d",i);
	push(s,i);
	i=2;
	printf("\n %d",i);
	push(s,i);
	i=3;
	printf("\n %d",i);
	push(s,i);
	i=pop(s);
	//printf("\n %d",i);
	i=pop(s);
	//printf("\n %d",i);
	i=pop(s);
	//printf("\n %d",i);
	return(0);
}
void initialise_stack(STACK *s){
	s->top=NULL;
}
int stack_empty(STACK *s){
	if(s->top==NULL){
		return(1);
	}
	else{
		return(0);
	}
}
void push(STACK *s,listentry entry){
	Node * p;
	p=(Node *)malloc(sizeof(Node));
	if(p==NULL){
		printf("Exhausted memory");
	}
	else{
		p->entry=entry;
		p->next=s->top;
		s->top=p;	
	}
}
listentry pop(STACK *s){
	Node *p;
	listentry c;
	if(s->top==NULL){
		printf("No element to be popped");
	}
	else{
		p=s->top;
		printf("\n Stack Top %d is popped",p->entry);
		c=p->entry;
		s->top=p->next;
		free(p);
		
	}
	return(c);
}
