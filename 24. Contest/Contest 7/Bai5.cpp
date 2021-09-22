#include<bits/stdc++.h>
using namespace std;

string s;
int d;

void solve()
{
	stack <int> a;
	a.push(-1);
	d=0;
	for (int i=0;i<s.length();i++)
		if (s[i]=='(') a.push(i);
		else
		if (s[i]==')')
		{
			a.pop();
			if (!a.empty()) d=max(d,i-a.top());
			else a.push(i);
		}	
	cout<<d<<"\n";
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
