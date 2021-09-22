#include<bits/stdc++.h>
using namespace std;

int n,s,m;

void solve()
{
	if (m>n||m*7>n*6) 
	{
		cout<<"-1"<<"\n";
		return;
	}
	else 
	{
	 	int x=m*s/n;
	 	if ((m*s)%n!=0) x++;
	 	cout<<x<<"\n";	
	}	
}

main()
{
	int t;
	cin>>t;
	for (int i=1;i<=t;i++)
	{
		cin>>n>>s>>m;
		solve();
	}
}
