#include<bits/stdc++.h>
using namespace std;

long long a[40],s,d,n;

void solve()
{
	for (int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	d=0; 
	int i=n;
	while (s>0 && i>0)
	{
		while (s>=a[i])
		{
			s=s-a[i];
			d++;
		}
		i--;
	}
	if (s>0) cout<<"-1"<<"\n";
	else cout<<d<<"\n";
}

main()
{
	int t;
	cin>>t;
	for (int i=1;i<=t;i++)
	{
		cin>>n>>s;
		solve();
	}
}
