//C program for merge sort
//O(nlogn)
#include<stdio.h>
void merge(int a[], int l, int m, int h)
{
	int i = l;
	int j = m + 1;
	int k=l, c[100];
	while((i<=m) && (j<=h))
	{
		if(a[i]<=a[j])
		{
			c[k++] = a[i++];
		}
		else
		{
			c[k++] = a[j++];
		}
	}
	while(i<=m)
	{
		c[k++] = a[i++];
	}
	while(j<=h)
	{
		c[k++] = a[j++];
	}
	for(i=l;i<=h;i++)
	{
		a[i] = c[i];
	}	
}

int mergesort(int a[], int l, int h)
{
	if(l<h)
	{
		int m = (l+h)/2;
		mergesort(a, l, m);
		mergesort(a, m+1, h);
		merge(a, l, m, h);
	}
}

int main()
{
	int n, z;
	printf("Enter the size of array\n");
	scanf("%d",&n);
	int a[n];
	printf("\nEnter the values\n");
	for(z=1; z<=n;z++)
	{
		scanf("%d",&a[z]);
	}
	mergesort(a, 1, n);
	for(z=1; z<=n ;z++)
	{
		printf("%d ",a[z]);
	}
}
