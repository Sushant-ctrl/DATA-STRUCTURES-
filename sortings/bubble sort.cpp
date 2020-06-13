//c program to implement bubble sort

#define size 10
#include <stdio.h>
int bubble(int []);
int swap(int [],int ,int);
int main()
{
	int a[size],i;
	for(i=0;i<size;i++)
	{
		scanf("%d",&a[i]);
	}
	bubble(a);
	for(i=0;i<size;i++)
	{
		printf("%d\t",a[i]);
	}
	return 0;
}
int bubble(int a[])
{
	int i,j;
	for (i=0;i<size;i++)
	{
		for (j=0;j<size-i;j++)
		{
			if (a[j]>a[j+1])
			{
				printf("a[i]=%d\ta[i+1]=%d",a[i],a[j]);
				swap(a,j,j+1);
				printf("a[i]=%d\ta[i+1]=%d",a[i],a[j]);
			}
		}
	}
	return 0;
}
int swap(int a[],int i,int j)
{
	printf("a[i]=%d\ta[i+1]=%d",a[i],a[j]);
	int temp=a[i];
	a[i]=a[j];
	a[j]=temp;
	printf("a[i]=%d\ta[i+1]=%d",a[i],a[j]);
	return 0;
}
