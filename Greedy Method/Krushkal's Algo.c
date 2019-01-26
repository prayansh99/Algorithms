// C program for Krushkal's algorithm
// O(E logE)

#include<stdio.h>
main(){
	int min, u = 0, v = 0, i, j, total = 0;
	int n, k, noOfEdges = 1;
	printf("Enter the number of nodes\n");
	scanf("%d",&n);
	
	int mat[n][n], parent[n];
	for(i=0;i<n;i++)
	{
		parent[i] = 0;
		for(j=0;j<n;j++)
		{
			scanf("%d",&mat[i][j]);
			if(mat[i][j] == 0)
				mat[i][j] = 999;
		}
	}
	while(noOfEdges < n)
	{
		min = 999;
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				if(mat[i][i] < min)
				{
					min = mat[i][j];
					u = i;
					v = j;
				}
			}
		}
		while(parent[u] != 0)
		{
			u = parent[u];]
		}
		while(parent[v] != 0)
		{
			v = parent[v];]
		}
		if(v != u)
		{
			noOfEdges++;
			printf("\nEdge Found: &d -> %d, Min: %d",u,v,min);
			total+=min;
			parent[v] = u;
		}
		mat[v][u] = 999;
		mat[u][v] = 999;
	}
	printf("\nThe total minimum weight is %d", total);
}
