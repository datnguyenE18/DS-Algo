#include<bits/stdc++.h>
using namespace std;

priority_queue <int,vector<int>,less<int> > a;
int b[100],k;
string s;

void solve()
{
	memset(b,0,sizeof(b));
	for (int i=0;i<s.length();i++)
		b[s[i]-'A']++;
	for (int i=0;i<26;i++)
		if (b[i]>0) a.push(b[i]);
	while(k>0)
	{
		int x=a.top();
		a.pop();
		x--;
		if (x>0) a.push(x);
		k--;
	}
	int d=0;
	while(!a.empty())
	{
		int x=a.top();
		a.pop();
		d=d+x*x;
	}
	cout<<d<<"\n";
}

main()
{
	int t;
	cin>>t;
	for (int i=1;i<=t;i++)
	{
		cin>>k>>s;
		solve();
	}
}
