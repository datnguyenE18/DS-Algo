#include<bits/stdc++.h>
using namespace std;

int b[30],d;
string s;

void solve()
{
	memset(b,0,sizeof(b));
	for (int i=0;i<s.length();i++)
		b[s[i]-'A']++;
	int m=0;
	for (int i=0;i<26;i++)
		m=max(m,b[i]);
	if ((m-1)*(d-1)>s.length()-m) cout<<"-1"<<"\n";
	else cout<<"1"<<"\n";
}

main()
{
	int t;
	cin>>t;
	for (int i=1;i<=t;i++)
	{
		cin>>d>>s;
		solve();
	}
}
