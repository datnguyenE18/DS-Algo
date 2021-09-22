#include<bits/stdc++.h>
using namespace std;

string s;
int op,cl,d;

void solve()
{
	stack <int> a;
	for (int i=0;i<s.length();i++)
		if (!a.empty() && s[i]==')' && a.top()=='(') a.pop();
		else a.push(s[i]);
	op=cl=d=0;
	while (!a.empty())
	{
		if (a.top()=='(') op++;
		else cl++;
		a.pop();
	}
	d=op/2+cl/2+op%2+cl%2;
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
