# include <stdio.h>
# include <stdlib.h>
 
int count(int start, int end)
{
	int tot = 0,i;int left, right;
	if(start > end)
	{
		return 1;
	}
	if (start == end)
	{	
		return 1;
    }
	else
	{
		for(i = 0; i <= (end-start) ;i++)
		{
			int counter = 0;
			left=0; right=0; 
			left += count(start, start+i-1);
			right += count(start+i+1, end);
 
			counter += left*right;
			tot += counter;
		}
	}
	return (tot);
 
}
int main ()
{
	int nodes = 0,i,n;
 
	printf("Enter the number of nodes in BST:");
	scanf("%d",&nodes);
	printf("%d\n",nodes);
	n = count(1,nodes);
	printf("\n%d",n);
	return 0;
}
