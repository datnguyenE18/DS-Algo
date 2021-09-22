#include<bits/stdc++.h>
using namespace std;

string s;
bool ok;

void solve()
{
	stack <int> a;
	for (int i=0;i<s.length();i++)
		if (s[i]==')')
		{
			ok=true;
			while (!a.empty() && a.top()!='(')
			{
				if (a.top()=='+'||a.top()=='-'||
				a.top()=='*'||a.top()=='/') ok=false;
				a.pop();
			}
			if (ok) break;
		}
		else a.push(s[i]);
	if (ok) cout<<"Yes"<<"\n";
	else cout<<"No"<<"\n";
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
