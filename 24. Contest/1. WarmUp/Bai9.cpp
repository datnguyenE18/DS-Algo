#include<bits/stdc++.h>
using namespace std;

void check(string s)
{
	int t=1,g=1;
	for (int i=0;i<s.length()-1;i++)
		if (s[i]>s[i+1])
		{
			t=0;
			break;
		} 
	for (int i=0;i<s.length()-1;i++)
		if (s[i]<s[i+1]) 
		{
			g=0;
			break;	
		}
	if (t==1||g==1) cout<<"YES"<<"\n";
	else cout<<"NO"<<"\n";
}

main()
{
	int t;
	string s;
	cin>>t;
	for (int i=1;i<=t;i++)
	{
		cin>>s;
		check(s);
	}
}
