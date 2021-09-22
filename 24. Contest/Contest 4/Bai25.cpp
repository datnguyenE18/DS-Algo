#include<bits/stdc++.h>
using namespace std; 

long long f[100];

char fibow(int n,long long k)
{
	if (n==1) return 'A';
	if (n==2) return 'B';
	if (k<=f[n-2]) return fibow(n-2,k);
	return fibow(n-1,k-f[n-2]);
}

main()
{
	int t,i,n; long long k;
	f[1]=1; f[2]=1;
	for (int i=3;i<93;i++) f[i]=f[i-2]+f[i-1];
	cin>>t;
	while(t--)
	{
		cin>>n>>k;
		cout<<fibow(n,k)<<"\n";
	}
}
