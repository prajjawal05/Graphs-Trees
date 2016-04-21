#include<bits/stdc++.h>
using namespace std;

int m[10000];
void DFS(int s,int v);
int a[100][100];
int main()
{
	int v,s;
	scanf("%d %d",&v,&s);
	//int a[v+1][v+1];
	for(int i=0;i<v;i++)
	{
		for(int j=0;j<v;j++)
			scanf("%d",&a[i+1][j+1]);
	}
	DFS(s,v);
}
void DFS(int s,int v)
{
	cout<<s<<" ";
	m[s]=1;
	for(int i=1;i<=v;i++)
	{
		if(!m[i]&&a[s][i]==1)
		{
			DFS(i,v);
		}
	}
}
//can also be done by queue
//mark parents for everyunmarked child
