#include<bits/stdc++.h>
using namespace std;

int b[30],ok;
string s;

void solve()
{
	memset(b,0,sizeof(b));
	for (int i=0;i<s.length();i++)
		b[s[i]-'a']++;
	int m=0;
	for (int i=0;i<26;i++)
		m=max(m,b[i]);
	int d=0;
	for (int i=0;i<26;i++) d=d+b[i];
	if (d-m+1>=m) cout<<"1"<<"\n";
	else cout<<"-1"<<"\n";
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
