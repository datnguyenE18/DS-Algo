#include<bits/stdc++.h>
using namespace std;

long long a[100000];
int n;

main()
{
	cin>>n;
	for (int i=0;i<n;i++)
		cin>>a[i];
	sort(a,a+n);
	for (int i=0;i<n;i++) cout<<a[i]<<" ";
	cout<<"\n";
}
