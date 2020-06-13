#define size 5

#include<stdio.h>
int partition(int [], int, int);
int dutchalgo(int [],int ,int ,int *,int *);
void swap(int [],int ,int);
void quicksort(int [], int, int);
int main()
{
	int a[size];
	int i=0;
	for (i=0;i<size;i++)
	{
		scanf("%d",&a[i]);
	}
	quicksort(a,0,size-1);
	for (i=0;i<size;i++)
	{
		printf("%d\t",a[i]);
	}
	return 0;
}
/*
int partition(int a[],int i,int j)
{
	int pivot=i;
	if (i>=j)
	{
		return -1;
	}
	while (i<j)
	{
		while (a[i]<=a[pivot])
		{
			i++;
		}
		while(a[j]>a[pivot])
		{
			j--;
		}
		if (i<j)
		{
			int temp=a[i];
			a[i]=a[j];
			a[j]=temp;
		}
	}
	int temp1=a[pivot];
	a[pivot]=a[j];
	a[j]=temp1;
	return j;
}
*/
void quicksort(int a[], int i, int j)
{
	int ret=0;
	int pivot=0,pivot1=0;
	ret = dutchalgo(a, i, j,&pivot,&pivot1);
	printf("%d %d\n",pivot1-i,pivot-i);
	if (ret==-1)
	{
		return;
	}
	//quicksort (a, i, ret-1);
	quicksort(a,i,pivot-1);
	//quicksort (a, ret+1, j);
	quicksort(a,pivot1+1,j);
}
int dutchalgo(int a[],int s,int f,int *p,int *p1)
{
	*p=s;
	*p1=s;
	if (s>f)
	{
		return -1;
	}
	int i=s+1;
	
	while (i<=f)
	{
		if (a[i]<a[*p] && *p1<=f)
		{
			swap(a,i,*p1+1);
			swap(a,*p,*p1+1);
			*p++;
			*p1++;			
		}
		else
		{
			if (a[i]==a[*p])
			{
				swap(a,*p1+1,i);
				*p1++;
				//a[i];
			}
		}
		i++;
	}
	return 0;
}
void swap(int a[],int i,int j)
{
	int temp=a[j];
	a[j]=a[i];
	a[i]=temp;
}
