#include<stdio.h>

#define size 5
#define true 1
#define false 0

typedef int Bool;

typedef char stack_entry;

typedef struct stack
{
	stack_entry entry[size];
	int top;
}Stack;

void initalizeStack(Stack *s);
void push(char d,Stack *s);
stack_entry pop(Stack *s);
Bool IsStackempty(Stack s);
Bool IsStackfull(Stack s);

int main ()
{
	Stack s;
	stack_entry x;
	int choice = -1;
	while (choice)
	{
		printf("enter ur choice\n 1.push \n 2.pop \n 3.empty \n 4.full \n 0.exit\n");
		scanf("%d",&choice);
		switch (choice)
		{
			case 1:
				printf("enter the data item u want to push\n");
				fflush(stdin);
				scanf("%c",&x);
				if (!IsStackfull(s))
				{
					push(x,&s);
				}
				else
				{
					printf("\nstack is full");
				}
				break;
			case 2:
				x=pop(&s);
				if (x!='\0')
				{
					printf("\n the popped element is %c",x);
				}
				else 
				{
					printf("\nthe stackk is empty");
				}
				break;
			case 3:
				x=IsStackempty(s);
				if (x)
				{
					printf("\n stack is empty");
				}
				else 
				{
					printf("\nstack is not empty");
				}
				break;
			case 4:
				x=IsStackfull(s);
				if (x)
				{
					printf("\nstack is full");
				}
				else
				{
					printf("\nstack is not full");
				}
				break;
			default:
				printf("\nprogram over");
		}
	}
	return 0;
}

void initalize(Stack *s)
{
	s->top=-1;
}

void push (stack_entry d,Stack *s)
{
	if (IsStackfull(*s)==false)
	{
		s->top=s->top+1;
		s->entry[s->top];
	}
}

stack_entry pop(Stack *s)
{
	char ans;
	if (IsStackempty(*s)==false)
	{
		ans = s->entry[s->top];
		s->top = s->top - 1;
	}
	else
	{
		ans = '\0';
	}
	return ans;
}

Bool IsStackempty(Stack s)
{
	if(s.top == -1)
	{
		return (true);
	}
	else
	{
		return (false);
	}
}

Bool IsStackfull(Stack s)
{
	if(s.top == size-1)
	{
		return (true);
	}
	return (false);
}
