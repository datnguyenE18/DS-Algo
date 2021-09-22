#include<bits/stdc++.h>
using namespace std;

string s;

void solve()
{
	stack <string> a;
	string x="";
	for (int i=s.length()-1;i>=0;i--)
	{
		if (s[i]=='+'||s[i]=='-'||s[i]=='*'||s[i]=='/')
		{
			string y="";
			y=y+a.top();
			a.pop();
			y=y+a.top()+s[i];
			a.pop();
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
