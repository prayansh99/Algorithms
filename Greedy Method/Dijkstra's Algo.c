// C program for Dijkstra's
// O(E logV)

#include<stdio.h>
#include <stdbool.h>
#include<limits.h>
#define size 10

//Finds the minimum in D[] amongst vertices which
//are not yet traversed
int min(int D[],bool S[], int n){
	int i,min_index,min;
	min = INT_MAX;
	for(i=0;i<n;i++){
		if(!S[i])
			if(D[i]<min){
				min=D[i];
				min_index=i;
			}
	}
	return min_index;
}

//Calculates shortest paths from source vertex
void ShortestPaths(int source, int cost[size][size], int n){
	int i, D[n]; bool S[n];
	for(i=0;i<n;i++){
		S[i]=false;
		D[i]=cost[source][i];
	}
	S[source] = true;
	D[source] = 0;
	for(i=1;i<n;i++){
		int u = min(D,S,n);
		S[u] = true;
		i=0;
		while(i<n){
			if(!S[i]){
				if(cost[u][i]!=INT_MAX&&u!=i){
					if(D[i]>D[u]+cost[u][i])
						D[i] = D[u]+cost[u][i];
						i++;
					}
				else i++;
			}
			else i++;
		}
	}
	for(i=0;i<n;i++){
		printf("\n%d -- %d : %d", source, i, D[i]);
	}
}

//Main function
int main(){
	int n,i,j,source,cost[size][size];
	printf("Enter number of vertices:");
	scanf("%d",&n);
	printf("\nEnter the cost adjacency matrix:\n");
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			scanf("%d",&cost[i][j]);
			if(i!=j&&cost[i][j]==0){
				cost[i][j]=INT_MAX;
			}
		}
	}
	printf("\nEnter the source vertex:");
	scanf("%d",&source);
		
	ShortestPaths(source, cost, n);
	return 0;
}
