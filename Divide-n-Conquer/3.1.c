//C program to find 2 elements whose sum is k with O(nlogn)
#include<stdio.h>
main()
{
	int i=0, j, n, k, nk;
	printf("Enter the number of elements\n");
	scanf("%d",&n);
	int a[n];
	printf("Enter the elements in sorted form\n");
	for(j=0;j<n;j++){
		scanf("%d",&a[j]);
	}
	printf("Enter the sum to search\n");
		scanf("%d",&k);
	for(j=0;j<n;j++){
		nk=k-a[j];
		int l=j, h=n-1;
		do{
			int m=(l+h)/2;
			if(a[m]==nk){
				printf("\nElement found\n");
				i=1;
				break;
			}
			else if(a[m]>nk){
				h=m-1;
			}
			else{
				l=m+1;
			}
		}while(i==0 && l<=h);
		if(i==0)
			break;
	}
	if(i==0)
		printf("\nElement not found\n");
}
