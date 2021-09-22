#include<bits/stdc++.h>
using namespace std; 

int convert(char a)
{
	return a-'0';
}
void solve(int v,string s)
{
	s=s+" ";
	int x=0;
	for (int i=0;i<s.length();i++)
		if (s[i]==' ')
		{
			int a=0;
			for (int j=x;j<i;j++) a=a*10+convert(s[j]);
			if (a>v) cout<<v<<" "<<a<<"\n";
			x=i+1;
		}	
} 

main()
{
	int n;
	cin>>n;
	//cin.ignore();
	for (int i=1;i<=n;i++)
	{
		string s;
		cin.ignore();
		getline(cin,s);
		solve(i,s);
	}
}
