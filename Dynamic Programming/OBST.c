// C program for OBST
// O(n^3)

#include<stdio.h>
void wh(int z, int n, int w[n][n], int p[n], int q[n])
{
	int i, j;
	for(i=0,j=z;i<=n&&j<=n;j++,i++)
	{
		if(i==j)
		{
			w[i][j] = q[i];
			//printf(" Q = %d\n",w[i][j]);
		}
		
		else
		{
			w[i][j] = p[j] + q[j] + w[i][j-1];			
		}	
		//printf(" W(%d,%d) = %d\t",i,j,w[i][j]);			
	}
	//printf("\n");
}

void ch(int z, int n, int w[n][n], int c[n][n], int r[n][n])
{
	int i, j, k, b, min; 
	for(i=0,j=z;i<=n&&j<=n;j++,i++)
	{
		min = 999;
		if(i==j)
		{
			c[i][j] = 0;
			r[i][j] = 0;
			//printf(" C = %d\n",c[i][j]);
		}
		else
		{
			k = i+1;
			while(k<=j && k>i)
			{
				if(min > c[i][k-1] + c[k][j])
				{
					min = c[i][k-1] + c[k][j];
					b = k;
				}
				k++;
			}
			c[i][j] = min + w[i][j];
			r[i][j] = b;
			//printf(" C = %d\n",c[i][j]);
		}
		//printf(" C(%d,%d) = %d\t",i,j,c[i][j]);
		//printf(" R(%d,%d) = %d\t",i,j,r[i][j]);
	}
	//printf("\n");
}

void print1(int z, int n, int w[n][n])
{
	int i, j;
	for(i=0,j=z;i<=n&&j<=n;j++,i++)
		printf(" W(%d,%d) = %d\t",i,j,w[i][j]);
	printf("\n");
}

void print2(int z, int n, int c[n][n])
{
	int i, j;
	for(i=0,j=z;i<=n&&j<=n;j++,i++)
		printf(" C(%d,%d) = %d\t",i,j,c[i][j]);
	printf("\n");
}

void print3(int z, int n, int r[n][n])
{
	int i, j;
	for(i=0,j=z;i<=n&&j<=n;j++,i++)
		printf(" R(%d,%d) = %d\t",i,j,r[i][j]);
	printf("\n");
}

int main()
{
	int i, j, z = 0, n, a = 0;

	printf("Enter the number of operations\n");
	scanf("%d",&n);
	int p[n], q[n+1], w[n+1][n+1], r[n+1][n+1], c[n+1][n+1];

	printf("Enter the probability of internal nodes\n");
	for(i=1;i<=n;i++)
	{
		scanf("%d",&p[i]);
	}

	printf("Enter the probability of external nodes\n");
	for(i=0;i<=n;i++)
	{
		scanf("%d",&q[i]);
	}

	for(z=0; z<=n; z++)
	{
		wh(z,n,w,p,q);	
	}
	
	for(z=0; z<=n; z++)
	{
		ch(z,n,w,c,r);
	}		
	
	for(z=0; z<=n; z++)
	{
		print1(z, n, w);
		print2(z, n, c);
		print3(z, n, r);
	}

/*	for(i=0,j=z;i<=n&&j<=n;j++,i++)
	{
		if(a==0 && j<=n)
		{
			printf("W(%d,%d) = %d\t",i,j,w[i][j]);
			if(j==n)
			{
				a = 1;
				printf("\n");
				i = 0;
				j = z;
			}
		}
		if(a==1)
		{
			printf("C(%d,%d) = %d\t",i,j,c[i][j]);
			if(j==n)
			{
				a = 2;
				printf("\n");
				i = 0;
				j = z;
			}
		}
		if(a==2)
		{
			printf("R(%d,%d) = %d\t",i,j,r[i][j]);
			if(j==n)
			{
				a = 0;
				z++;
				printf("\n");
				i = -1;
				j = z-1;
			}
		}
	}*/
}
