#include<bits/stdc++.h>
using namespace std;

string s;

int bac(char x)
{
	if (x=='+'||x=='-') return 2;
	else
	if (x=='*'||x=='/') return 3;
	else
	if (x=='^') return 4;
	else return 1;
}

void solve()
{
	stack <char> a;
	string x="";
	for (int i=0;i<s.length();i++)
	{
		if (s[i]=='(') a.push(s[i]);
		else
		if (s[i]==')')
		{
			while(!a.empty() && a.top()!='(')
			{
				x=x+a.top();
				a.pop();
			}
			a.pop();
		}
		else
		if (s[i]=='+'||s[i]=='-'||
		s[i]=='*'||s[i]=='/'||s[i]=='^')
		{
			while (!a.empty() && bac(a.top())>=bac(s[i]))
			{
				x=x+a.top();
				a.pop();
			}
			a.push(s[i]);
		}
		else x=x+s[i];
	}
	while(!a.empty()) 
	{
		if (a.top()!='(') x=x+a.top();
		a.pop();
	}
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
