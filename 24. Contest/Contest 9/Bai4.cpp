#include<bits/stdc++.h>
using namespace std; 

int v,g[2000][2000];

int convert(char a)
{
	return a-'0';
}

void print()
{
	for (int i=1;i<=v;i++)
	{
		for (int j=1;j<=v;j++) cout<<g[i][j]<<" ";
		cout<<"\n";
	}	
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
			g[v][a]=1;
			x=i+1;
		}
} 

main()
{
	memset(g,0,sizeof(g));
	cin>>v;
	cin.ignore();
	for (int i=1;i<=v;i++)
	{
		string s;
		getline(cin,s);
		solve(i,s);
	}
	print();
}
