// C program to find the triplet
//O(n**2)
#include <stdio.h>
int main()
{
	int  i, s, n, j=0;
	printf("Enter the size of array\n");
	scanf("%d",&n);
    int a[n];
    printf("\nEnter the array\n");
    for(i=0;i<n;i++){
    	scanf("%d",&a[i]);
	}
    printf("Enter the sum\n");
    scanf("%d",&s);
 	
 	int l, r;
    for (i = 0; i < n - 2; i++) {
        l = i + 1;
 	r = n - 1;
        while (l < r) {
            if (a[i] + a[l] + a[r] == s) {
                printf("\nTriplet is %d, %d, %d\n", a[i], a[l], a[r]);
                j=1;
                break;
            }
            else if (a[i] + a[l] + a[r] < s)
                l++;
            else
                r--;
        }
    }
    if(j==0)
    	printf("\nElements not found\n");
    return 0;
}
