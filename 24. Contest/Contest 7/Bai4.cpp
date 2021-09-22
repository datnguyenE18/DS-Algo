#include<bits/stdc++.h>
using namespace std;

void solve(string s)
{
	stack <char> a;
	bool ok=true;
	for (int i=0;i<s.length();i++)
	{
		if (s[i]=='('||s[i]=='['||s[i]=='{') a.push(s[i]);
		else 
		if (s[i]==')')
		{
			if (a.empty())
				{
					ok=false;
					break;
				}
			else
			if (a.top()=='(') a.pop();
		}
		else 
		if (s[i]==']')
		{
			if (a.empty())
				{
					ok=false;
					break;
				}
			else
			if (a.top()=='[') a.pop();
		}
		else 
		if (s[i]=='}')
		{
			if (a.empty())
				{
					ok=false;
					break;
				}
			else
			if (a.top()=='{') a.pop();
		}		
	}
	if (!a.empty()) ok=false;
	if (ok) cout<<"YES"<<"\n";
	else cout<<"NO"<<"\n";
}

main()
{
	int t;
	string s;
	cin>>t;
	for (int i=1;i<=t;i++)
	{
		cin>>s;
		solve(s); 
	}
}
