#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int prime ( int m, ll n ) {
	int count = 0;
	for ( ll i = 2; i <= sqrt ( n ); i++ ) {
		int temp = 0;
		for ( int j = 2; j <= sqrt ( i ); j++ ) {
			if ( i % j == 0 ) {
				temp = 1;
				break;
			}
		} if ( temp ) continue;
		if ( i*i >= m && i*i <= n ) count++;
	} return count;
}

int main () {
	ll n;
	int t, m; cin >> t;
	while ( t-- ) {
		cin >> m >> n;
		cout << prime ( m, n ) << endl;
	} system ( "pause" );
}