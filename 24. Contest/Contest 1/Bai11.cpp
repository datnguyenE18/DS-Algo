#include<bits/stdc++.h>
using namespace std;

string s;

void solve()
{
	string x="";
	x=x+s[0];
	for (int i=1;i<s.length();i++)
		if (s[i]=='1')
		{
			if (x[x.length()-1]=='0') x=x+'1';
			else x=x+'0';
		}
		else x=x+x[x.length()-1];
	cout<<x<<"\n";
}

main()
{
	int t;
	cin>>t;
	for (int i=1;i<=t;i++)
	{
		cin>>s;
		solve();
	}
}
