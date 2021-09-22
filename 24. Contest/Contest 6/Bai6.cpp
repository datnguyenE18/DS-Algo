#include<bits/stdc++.h> 
using namespace std;

int t,n,x; 
int b[3]; 

void xuli(int n)
{
	for (int i=0;i<=2;i++) b[i]=0;
	for (int i=0;i<n;i++) 
		{
			cin>>x;
			if (x==0) b[0]++;
			else if(x==1) b[1]++;
			else if(x==2) b[2]++; 
		}
	for (int i=1;i<=b[0];i++) cout<<"0 ";
	for (int i=1;i<=b[1];i++) cout<<"1 ";
	for (int i=1;i<=b[2];i++) cout<<"2 ";
	cout<<"\n"; 
}

main()
{
	cin>>t;
	for (int k=1;k<=t;k++)
	{
		cin>>n;
		xuli(n);	
	} 
}


