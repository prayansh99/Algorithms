// C program for MCM 
// O(n^3)

#include<stdio.h>
int main(){
	int i,j,n,f,kval,min,g,k;
	printf("\nEnter the total number of matrices:\n");
	scanf("%d",&n);
	int cost[n+1],karr[n][n],mat[n][n];
	printf("Enter the values of:\n");
	for(i=0;i<=n;i++){
		printf("P%d :\t",i);
		scanf("%d",&cost[i]);
	}
	for(i=0;i<n;i++)
		for(j=0;j<n;j++){
			mat[i][j]=100000;
			karr[i][j]=0;
		}
	for(g=0;g<n;g++){
		for(i=0;i<n;i++){
			j=i+g;
			if(i==j){
				mat[i][j]=0;
			}
			else{
				int min=1000000;
				for (k=i;k<=j-1;k++){
					f=mat[i][k]+mat[k+1][j]+cost[i]*cost[k+1]*cost[j+1];
					if(f<min){
						min=f;
						karr[i][j]=k+1;
					}
				}
			mat[i][j]=min;
			}
		}
	}
	for(i=0;i<n;i++)
			printf("M%d%d = 0\n",i+1,i+1);
	k=0;
	for(i=0;i<n;i++){
		for(j=0;j<k;j++){
			printf("M%d%d = %d ( k = %d )\n",j+1,i+1,mat[j][i],karr[j][i]);
		}
		k=k+1;
	}

	printf("\nMinimum number of scalar multiplications required: %d",mat[0][n-1]);
}
