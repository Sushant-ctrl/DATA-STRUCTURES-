#include<stdlib.h> 
#include<stdio.h> 
#define size 6
void merge(int a[],int l,int m,int r)
{
	int i,j,k;
	int n1=m-l+1;
	int n2=r-m;
	
	int L[n1],R[n2];
	
	for (i=0;i<n1;i++)
	{
		L[i]=a[l+i];
	}
	for (i=0;i<n2;i++)
	{
		R[i]=a[m+1+i];
	}
	
	i=0;
	j=0;
	k=l;
	
	while(i<n1&&j<n2)
	{
		if (L[i]<=R[j])
		{
			a[k]=L[i];
			i++;
		}
		else
		{
			a[k]=R[j];
			j++;
		}
		k++;
	}
	
	while(i<n1)
	{
		a[k]=L[i];
		i++;
		k++;
	}
	while(j<n2)
	{
		a[k]=R[j];
		j++;
		k++;
	}
}

void mergesort(int a[],int l,int r)
{
	if(l<r)
	{
		int m=l+(r-l)/2;
		mergesort(a,l,m);
		mergesort(a,m+1,r);
		merge(a,l,m,r);
	}
}

int main()
{
	 int a[size];
	 int i;
	 for (i=0;i<size;i++)
	 {
	 	scanf("%d",&a[i]);
	 }
	 mergesort(a,0,size-1);
	 for (i=0;i<size;i++)
	 {
	 	printf("\n%d",a[i]);
	 }
	 return 0;
}
