#include<bits/stdc++.h>
using namespace std;

int ok[20],a[20],n;

void tryy(int x)
{
	for (int i=n;i>0;i--)
		if (ok[i]==0)
		{
			ok[i]=1;
			a[x]=i;
			if (x==n)
			{
				for (int j=1;j<=n;j++) cout<<a[j];
				cout<<" ";
			}
			else tryy(x+1);
			ok[i]=0;
		}
}

main()
{
	int t;
	cin>>t;
	for (int i=1;i<=t;i++)
	{
		cin>>n;
		memset(ok,0,sizeof(ok));
		tryy(1);
		cout<<"\n";
	}
}
