#include <bits/stdc++.h>
using namespace std;
#define IOS() ios_base::sync_with_stdio(0);cin.tie(0); cout.tie(0);
typedef long long int ll;

main()
{
	IOS();
	int T,N;
	ll *A,*B;
	cin>>T;
	while(T--){
		cin>>N; 
		A = new ll [N];
		B = new ll [N];
		for(int i = 0 ; i < N ; i++){
			cin>>A[i];
			B[i]=A[i];
		}
		int l,r;
		sort(A,A+N);		
		for(int i = 0 ; i < N ; i++){
			if(A[i]!=B[i]){
			l = i+1;
			break;
			}
		}
		for(int i = 0 ; i < N ; i++){
			if(A[i]!=B[i]) r = i + 1;
		}
		cout<<l<<" "<<r<<"\n";
	}
}
// hii

