#include<bits/stdc++.h>
using namespace std;

int n,u,c,g[100][100],ok[100],d[100],pre[100];

void dijkstra(int s)
{	//Initialize
	d[s]=0;
	ok[s]=1;    //T=V\{u}
	c--;
	for (int i=1;i<=n;i++)  
	{
		d[i]=g[s][i];
		pre[i]=s;
	}
	while (c>0) //loop
	{
		int x;
		int min=max;
		for (int i=1;i<=n;i++)   //find min
			if (ok[i]==0 && d[i]<min)
			{
				x=i;
				min=d[i];	
			}
		ok[x]=1; //T=T\{x}
		c--;
		for (int i=1;i<=n;i++) //using x to re-assign label to other vertices
			if (ok[i]==0 && g[x][i]!=max && d[x]!=max && (d[i]>d[x]+g[x][i]))
			{
				d[i]=d[x]+g[x][i];
				pre[i]=x;	
			}
	}
}

void khoitao()
{
	c=n; 
	memset(ok,0,sizeof(ok));
	for (int i=1;i<=n;i++) 
	{
		pre[i]=i;
		d[i]=max;
	}
}

void solve(int v,int e,int u)
{
	int x,y,z;
	for (int i=1;i<=e;i++)
	{
		cin>>x>>y>>z;
		a[x].push_back(y);
		a[y].push_back(x);
	}
}

main()
{
	int t,v,e,u;
	for (int i=1;i<=t;i++)
	{
		cin>>v>>e>>u;
		a=new vector <int> [v+1];
		solve(v,e,u);
	}
}
