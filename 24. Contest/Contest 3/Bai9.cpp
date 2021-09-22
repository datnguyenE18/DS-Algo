#include<bits/stdc++.h>
using namespace std;

struct work
{
	int id;
	int d;
	int p;
};

int n,s,c;
work w[1001];
bool b[1001];

bool cmp(work a,work b)
{
	return a.p>b.p;
}

void solve()
{
	for (int i=1;i<=n;i++) cin>>w[i].id>>w[i].d>>w[i].p;
	sort(w+1,w+n+1,cmp);
	memset(b,false,sizeof(b));
	s=0; c=0;
	for (int i=1;i<=n;i++)
	{
		while (b[w[i].d] && w[i].d>0) w[i].d--;
		if (!b[w[i].d] && w[i].d>0) 
		{
			b[w[i].d]=true;
			s=s+w[i].p;
			c++;
		}
	}
	cout<<c<<" "<<s<<"\n";
}

main()
{
	int t;
	cin>>t;
	for (int i=1;i<=t;i++)
	{
		cin>>n;
		solve();
	}
}

