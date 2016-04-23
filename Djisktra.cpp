//distance
//mark
//minimum
#include<bits/stdc++.h>
int a[100][100];
using namespace std;
void dijkstra(int v,int s);
int mindis(int dis[],int m[],int v)
{
	int minm=INT_MAX,mini;
	for(int i=0;i<v;i++)
	{
		if(!m[i]&&dis[i]<=minm)
		{
			minm=dis[i];
			mini=i;
		}
	}
	return mini;	
}
int main()
{
	int v,s;
	scanf("%d",&v);
	for(int i=0;i<v;i++)
		for(int j=0;j<v;j++)
			scanf("%d",&a[i][j]);
	for(int i=0;i<v;i++)
		for(int j=0;j<v;j++)
			printf("%d",a[i][j]);
	scanf("%d",&s);	//source
	//s--;	
	dijkstra(v,s);
	return 0;
}
void dijkstra(int v,int s)
{
	int dis[v],m[v];
	for(int i=0;i<v;i++)
	{
		dis[i]=INT_MAX;
		m[i]=0;
	}
	dis[s]=0;
	for(int i=0;i<v-1;i++)	//number of vertices__last one will be done automatically
	{
		int l=mindis(dis,m,v);
		m[l]=1;
		for(int j=0;j<v;j++)
		{
			if(!m[j]&&a[l][j]&&dis[l]+a[l][j]<dis[j]&&dis[l]!=INT_MAX)
				dis[j]=dis[l]+a[l][j];
		}
	}
	for(int i=0;i<v;i++)
		printf("%d %d\n",i+1,dis[i]);
}
