// C program for prim's algorithm
// O(n**2)
#include<stdio.h>
int main()
{
	int min, u = 0, v = 0, i, j, total = 0;
	int n, k;
	printf("Enter the number of nodes\n");
	scanf("%d",&n);
	
	int mat[n][n], vis[n];
	printf("Enter the values\n");
	for(i=0;i<n;i++)
	{
		vis[i] = 0;
		for(j=0;j<n;j++)
		{
			scanf("%d",&mat[i][j]);
			if(mat[i][j] == 0)
				mat[i][j] = 999;
		}
	}

	
	vis[0] = 1;
	
	//algo
	for(k = 0; k < n-1; k++)
	{
		min = 999;
		for(i = 0; i < n; i++)
		{
			if(vis[i] == 1)
			{
				for(j = 0;j < n;j++)
				{
					
					if(vis[j] != 1)
					{
						if(min > mat[i][j])
						{
							min = mat[i][j];
							u = i;
							v = j;
						}
					}
				}
			}
		}
		vis[v] = 1;
		total += min;
		printf("\nEdge found: %d -> %d: Weight: %d\n",u,v,min);
	}
		printf("\nThe total minimum weight is %d",total);

}
