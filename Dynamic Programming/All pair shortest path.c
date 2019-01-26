// C program for All pairs shortest path
// O(V^3)

#include<stdio.h>
#define SIZE 100
int print_path(int path[SIZE][SIZE],int a,int b){
	if(path[a][b]==-1){
		printf("%d---%d",a+1,b+1);
		return 0;	
	}
	else{
		printf("%d---",a+1);
		a=path[a][b];
		print_path(path,a,b);
		return 0;
	}
}

int main(){
	int i,j,k,n,a,b,c;
	printf("\nEnter the number of vertices\n");
	scanf("%d",&n);
	int mat[n][n],path[SIZE][SIZE];
	printf("\nEnter the adjacency matrix\n");
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(i==j)
				mat[i][j]=0;
			else
				scanf("%d",&mat[i][j]);
			path[i][j]=-1;
		}
	}
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(i!=j){
				if(mat[i][j]==0)
					mat[i][j]=999;
			}
		}
	}	
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			for(k=0;k<n;k++){
				if(k==j)
					continue;
				a=mat[j][k];
				b=mat[j][i]+mat[i][k];
				if(b>=a)
					c=a;
				else
					c=b;
				if(c<mat[j][k]){
					path[j][k]=i;
				}
				mat[j][k]=c;
			}
		}
	}
	printf("\nThe final matrix is-\n");
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			printf("%d  ",mat[i][j]);
		}
		printf("\n");
	}
	printf("\nThe path matrix is=\n");
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(path[i][j]>0)
				printf("  %d",path[i][j]+1);
			else
				printf(" %d",path[i][j]);
		}
		printf("\n");
	}

	printf("\nAll shortest paths are-\n");
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(i==j)
				continue;
			printf("Path between %d and %d:\t",i+1,j+1);
			print_path(path,i,j);
			printf("\n");
		}
	}
		
		
	return 0;
}
