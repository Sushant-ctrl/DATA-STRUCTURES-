#include<stdio.h>

#define SIZE 5
#define True 1
#define False 0

typedef int BOOL;

typedef char stack_entry;

struct stack
{
	char stack_array[SIZE];
	int top;	
};
 
typedef struct stack STACK;
 
void initialize_stack(STACK*);
void push(stack_entry ,STACK*);
stack_entry pop(STACK*);
BOOL is_stack_empty(STACK);
BOOL is_stack_full(STACK);
 
int main()
{
	STACK s;
	stack_entry x;
	int choice = -1;
	initialize_stack(&s);
	while(choice)
	{
	printf("\nEnter your choice option. \n1 push \n2 pop \n0 exit\n");
	scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				printf("Enter the data item you want to push\n");
				fflush(stdin);
				scanf("%c",&x);
				if(!is_stack_full(s))
				{
					push(x,&s);
				}
				else
				{
					printf("The stack is full");
				}
				break;
			case 2:
				if(!is_stack_empty(s))
				{
					x = pop(&s);
					printf("\nThe popped item is%c",x);
				}
				else
				{
					printf("The stack is empty");
			    }
			    break;
			case 0:
				printf("BYE");
				break;
	    }
				
	}
}

void initialize_stack(STACK*s)
{
	s->top = -1;	
}

void push(stack_entry c,STACK* s)
{
	if(!is_stack_full(*s))
	{
		s->stack_array[(s->top)+1] = c;
		s->top++;
	}
}

stack_entry pop(STACK* s)
{
	stack_entry ans;
	if(!is_stack_empty((*s)))
	{
		ans = s->stack_array[s->top];
		s->top--;
	}
	return ans;
}

BOOL is_stack_empty(STACK s)
{
	if (s.top == -1)
		return True;
	else
		return False;
}

BOOL is_stack_full(STACK s)
{
	if (s.top == SIZE-1)
		return True;
	else
		return False;
}


