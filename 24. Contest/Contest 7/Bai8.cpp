#include<bits/stdc++.h>
using namespace std;

string s;

void solve()
{
	stack <int> a;
	for (int i=0;i<s.length();i++)
		if (s[i]=='(') a.push(i-1);
		else 
		if (s[i]==')')
		{
			if (a.top()==-1 || s[a.top()]=='+') continue;
			else 
			if (s[a.top()]=='-')
			{
				for (int j=a.top()+1;j<i;j++)
					if (s[j]=='+') s[j]='-';
					else
					if (s[j]=='-') s[j]='+';
			}
			if (!a.empty()) a.pop();
		}
	for (int i=0;i<s.length();i++)
		if (s[i]!='(' && s[i]!=')') cout<<s[i];
	cout<<"\n";
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
