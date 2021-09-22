#include<bits/stdc++.h>
using namespace std;

int n,x;
int a[30];
vector <vector <int> > r;
vector <int> v;

void tryy(int i,int s,vector <int> v)
{
	if (s>x) return;
	if (s==x) 
	{
		r.push_back(v);
		return;
	}
	for (int j=i;j<=n;j++) 
	{
		if (s+a[j]<=x) 
		{
			v.push_back(a[j]);
			tryy(j,s+a[j],v);
			v.pop_back();
		}
	}
}

main()
{
	int t;
	cin>>t;
	for (int i=1;i<=t;i++)
	{
		cin>>n>>x;
		for (int j=1;j<=n;j++) cin>>a[j];
		r.clear();
		v.clear();
		tryy(1,0,v);
		if (r.size()==0) cout<<"-1";
		else
		{
			for (int j=0;j<r.size();j++)
			{
				for (int k=0;k<r[j].size()-1;k++) 
					cout<<r[j][k]<<" ";
			}
		}
		cout<<"\n";	
	}
}
