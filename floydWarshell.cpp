#include<bits/stdc++.h>
using namespace std;
int main()
{
    int v=9;
	scanf("%d",&v);
	int a[v][v],i,j,k;
	
	for(i=0;i<v;i++)
	{
		for( j=0; j<v ;j++)
		{
			scanf( "%d" ,&a[i][j]);
		}
	}
	/*int a[9][9] = {{0, 4, 0, 0, 0, 0, 0, 8, 0},
                      {4, 0, 8, 0, 0, 0, 0, 11, 0},
                      {0, 8, 0, 7, 0, 4, 0, 0, 2},
                      {0, 0, 7, 0, 9, 14, 0, 0, 0},
                      {0, 0, 0, 9, 0, 10, 0, 0, 0},
                      {0, 0, 4, 0, 10, 0, 2, 0, 0},
                      {0, 0, 0, 14, 0, 2, 0, 1, 6},
                      {8, 11, 0, 0, 0, 0, 1, 0, 7},
                      {0, 0, 2, 0, 0, 0, 6, 7, 0}
                     };*/
	
	for(i=0;i<v;i++)
	{
		for(j=0;j<v;j++)
		{
			if(a[i][j]==0&&i!=j)
				a[i][j]=INT_MAX;
		}
	}
	for(k=0;k<v;k++)
	{
		for(i=0;i<v;i++)
		{
			for(j=0;j<v;j++)
			{
				if(a[i][k]!=INT_MAX&&a[k][j]!=INT_MAX&&i!=j)
					a[i][j]=min(a[i][j],a[i][k]+a[k][j]);
			}
		}
	}
	for(int i=0;i<v;i++)
		printf("%d %d\n",i,a[0][i]);
	return 0;	
	
}
