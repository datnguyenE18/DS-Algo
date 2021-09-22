#include<bits/stdc++.h>
using namespace std;

string s1,s2;

void convert(string &s)
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
}

void solve()
{
	string x,y;
	convert(s1);
	convert(s2);
	for (int i=0;i<s1.length();i++)
		if (s1[i]!='(' && s1[i]!=')') x=x+s1[i];
	for (int i=0;i<s2.length();i++)
		if (s2[i]!='(' && s2[i]!=')') y=y+s2[i];	
	if (x==y) cout<<"YES"<<"\n";
	else cout<<"NO"<<"\n";
}

main()
{
	int t;
	cin>>t;
	for (int i=1;i<=t;i++)
	{
		cin>>s1>>s2;
		solve();
	}
}
