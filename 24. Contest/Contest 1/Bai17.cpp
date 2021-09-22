#include<bits/stdc++.h>
using namespace std;

int n;

void solve()
{
	queue <long long> a;
	a.push(9);
	while(!a.empty())
	{
		long long x=a.front();
		a.pop();
		if (x%n==0)
		{
			cout<<x<<"\n";
			break;
		}
		else 
		{
			a.push(x*10);
			a.push(x*10+9);
		}
	}
}

main()
{
	int t;
	cin>>t;
	for (int i=1;i<=t;i++)
	{
		cin>>n;
		solve();
	}
}
