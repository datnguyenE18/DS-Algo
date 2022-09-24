#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;

long long powM(int n, int k) {
	if(k==0) return 1;
	long long tmp = powM(n,k/2);
	if(k%2==0) return (tmp*tmp)%mod;
	return ((n*tmp)%mod)*tmp%mod;
}

int main() {
	int t,k,n;
	cin>>t;
	while(t--) {
		cin>>n>>k;
		cout<<powM(n,k)<<endl;
	}

	return 0;
}