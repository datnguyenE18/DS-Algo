#include<bits/stdc++.h>
using namespace std;

/*void xaun(int n)
{
	string s="";
	for (int i=1;i<=n;i++) s=s+'A';
	cout<<s<<" ";
	while (1)
	{
		int i=n-1;
		while (i>=0 && s[i]=='B')
		{
			s[i]='A';
			i--;
		}
		if (i<0) return;
		s[i]='B';
		cout<<s<<" ";
	}
}*/

int a[10],n;

void tryy(int x)
{
	for (int i=0;i<=1;i++) 
	{
		a[x]=i;
		if (x==n) 
		{
			for (int j=1;j<=n;j++)
			{
				if (a[j]==0) cout<<"A";
				else cout<<"B";
			}
			cout<<" ";
		}
		else tryy(x+1);	
	}
}

main()
{
	int t;
	cin>>t;
	for (int i=1;i<=t;i++)
	{
		cin>>n;
		//xaun(n);
		tryy(1);
		cout<<"\n";
	}
}
