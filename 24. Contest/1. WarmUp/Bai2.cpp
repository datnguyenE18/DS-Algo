#include<bits/stdc++.h>
using namespace std;

main()
{
	int t;
	string s;
	cin>>t;
	for (int i=1;i<=t;i++)
	{
		cin>>s;
		if (s[0]==s[s.length()-1]) cout<<"YES"<<"\n";
		else cout<<"NO"<<"\n";
	}
}
