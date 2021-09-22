#include<bits/stdc++.h>
using namespace std;
#define MAX 1001
int g[MAX][MAX];
typedef vector <int> adj;

void solve(int v)
{
	//int g[2000][2000];
	vector <adj> a(v+1);
	for (int i=1;i<=v;i++)
		for (int j=1;j<=v;j++)
		{
			cin>>g[i][j];
			if (g[i][j]==1) a[i].push_back(j);
		}
	for (int i=1;i<=v;i++)
	{
		for (int j=0;j<a[i].size();j++) cout<<a[i][j]<<" ";
		cout<<"\n";
	}	
}

main()
{
	int v;
	cin>>v;
	solve(v);
}
