//C program to find elements from 2 arrays sum equals to k
#include <stdio.h>
int main()
{
	int  k, nk, i=0, s, n, j;
	printf("Enter the size of array\n");
	scanf("%d",&n);
    int a[n], b[n];
    printf("\nEnter the elements for 1st array\n");
    for(j=0;j<n;j++){
    	scanf("%d",&a[j]);
	}
	printf("\nEnter the elements for 2nd array\n");
    for(j=0;j<n;j++){
    	scanf("%d",&b[j]);
	}
    printf("Enter the sum\n");
    scanf("%d",&k);
    for(j=0;j<n;j++){
		nk=k-b[j];
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
