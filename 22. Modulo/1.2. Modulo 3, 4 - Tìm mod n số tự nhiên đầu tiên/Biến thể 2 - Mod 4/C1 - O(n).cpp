#include<bits/stdc++.h>
using namespace std;

void solve(int n, unsigned long int k) {
	unsigned long int res = 0;
	for ( int i = 1; i <= n; i++ )
		res += ( i % k );

	if ( res == k ) cout << 1 << endl;
	else cout << 0 << endl;
}

int main() {
	int t, n; cin >> t;
	unsigned long int k;
	while ( t-- ) {
		cin >> n >> k;
		solve(n, k);
	}
}