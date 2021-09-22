#include<bits/stdc++.h>
using namespace std;

int n,d4,d7;
bool ok;

void solve()
{
	ok=true;
	d4=d7=0;
	while(1)
	{
		if (n%7==0)
		{
			d7=n/7;
			break;
		}
		else
		if (n>=4)
		{
			n=n-4;
			d4++;
		}
		else 
		{
			ok=false;
			break;
		}
	}
	if (!ok) cout<<"-1";
	else
	{
		for (int i=1;i<=d4;i++) cout<<4;
		for (int i=1;i<=d7;i++) cout<<7;
	}
	cout<<"\n";
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
