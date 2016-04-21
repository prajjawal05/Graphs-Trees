#include<bits/stdc++.h>
using namespace std;
queue<int> q;
int main()
{
	int v,s,x;
	scanf("%d %d",&v,&s);
	int a[v+1]={0};
	int b[v+1][v+1];
	for(int i=1;i<=v;i++)
	{
		for(int j=1;j<=v;j++)
		{
			scanf("%d",&b[i][j]);
		}
	}
	q.push(s);
	//cout<<s<<" ";
	while(!q.empty())
	{
		x=q.front();
		q.pop();
		a[x]=1;
		for(int i=1;i<=v;i++)
		{
			if(b[x][i]==1&&a[i]==0){
				q.push(i);
				//cout<<i<<" ";
			}
		}
	}
	return 0;
}
//mark source for every unmarked child
