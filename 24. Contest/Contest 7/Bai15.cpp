#include<bits/stdc++.h>
using namespace std;

string s;

void solve()
{
	stack <string> a;
	for (int i=0;i<s.length();i++)
	{
		if (s[i]=='+'||s[i]=='-'||s[i]=='*'||s[i]=='/')
		{
			string y="";
			string x1=a.top();
			a.pop();
			string x2=a.top();
			a.pop();
			y=y+'('+x2+s[i]+x1+')';
			a.push(y);
		}
		else
		{
			string y="";
			y=y+s[i];
			a.push(y);
		}
	}
	cout<<a.top()<<"\n";
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
