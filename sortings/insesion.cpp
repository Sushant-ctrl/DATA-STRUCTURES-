#include<stdlib.h> 
#include<stdio.h> 
#define size 5
int merge(int a[],int l,int m,int r)
{
	int val=0;
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
			val=val+(m-i)+1;
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
	return val;
}

int mergesort(int a[],int l,int r)
{
	int val=0;
	if(l<r)
	{
		int m=l+(r-l)/2;
		val=mergesort(a,l,m);
		val+=mergesort(a,m+1,r);
		val+=merge(a,l,m,r);
	}
	return val;
}

int main()
{
	 int val; 
	 int a[size];
	 int i;
	 for (i=0;i<size;i++)
	 {
	 	scanf("%d",&a[i]);
	 }
	 val=mergesort(a,0,size-1);
	 for (i=0;i<size;i++)
	 {
	 	printf("\n%d",a[i]);
	 }
	 printf("\n%d",val);
	 return 0;
}
