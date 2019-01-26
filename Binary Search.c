//C program to search a value equals to its index
#include<stdio.h>
main()
{
	int k, n, i=0, j;
	printf("Enter the number of elements\n");
	scanf("%d",&n);
	int a[n];
	printf("Enter the elements in sorted form\n");
	for(j=0;j<n;j++){
		scanf("%d",&a[j]);
	}
	printf("Enter the element to search\n");
		scanf("%d",&k);
	int l=0, h=n-1;
	do{
		int m=(l+h)/2;
		if(a[m]==k){
			printf("\nElement found at %d position\n",m+1);
			i=1;
		}
		else if(a[m]>k){
			h=m-1;
		}
		else{
			l=m+1;
		}
	}while(i==0 && l<=h);
	if(i==0)
		printf("\nElement not found\n");
}
