#include<bits/stdc++.h>
using namespace std;

long long ts,ms;  

void solve()
{
	while(1)
	{
		if (ms%ts==0) 
		{
			cout<<"1/"<<ms/ts<<"\n";
			break;
		}
		else
		{
			long long n=ms/ts+1;
			cout<<"1/"<<n<<" + ";
			ts=n*ts-ms;
			ms=ms*n;
		}
	}
}

main()
{
	int t;
	cin>>t;
	for (int i=1;i<=t;i++)
	{
		cin>>ts>>ms;
		solve();
	}
}
