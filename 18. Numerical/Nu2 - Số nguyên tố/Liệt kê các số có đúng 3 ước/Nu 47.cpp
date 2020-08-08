#include<bits/stdc++.h>
using namespace std;
 
void prime(int n){
	bool prime[n+1];
	for(int i=2;i<=n;i++){
		prime[i]=true;
	}
	prime[0]=prime[1]=false;
	for(int i=2;i<=sqrt(n);i++){
		if(prime[i]==true)
			for(int j=i*i;j<=n;j+=i){
				prime[j]=false;
			}
	}
	for(int i=0;i<=sqrt(n);i++){
		if(prime[i]==true)cout<<i*i<<" ";
	}
	cout<<endl;
}
 
int main(){
	int t,n;
	cin>>t;
	while(t--){
	cin>>n;
	prime(n);}
}