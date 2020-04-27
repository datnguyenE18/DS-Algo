#include <iostream>
using namespace std;

int a[100000000], b[100000000], c[100000000],
k, n,
ans = 0;

int test () {
	for ( int i = 1; i <= k; i++ ) {
		if ( c[i] != b[i] )
			return 0;
	} return 1;
}

void backtrack ( int i ) {
	for ( int j = a[i - 1] + 1; j <= n - k + i; j++ ) {
		a[i] = j;
		if ( i == k ) {
			if ( test () ) {
				ans = 0;
				for ( int o = 1; o <= k; o++ ) {
					for ( int l = 1; l <= k; l++ ) {
						if ( a[o] == b[l] ) ans++;
					}
				}
			}
			for ( int u = 1; u <= k; u++ )
				c[u] = a[u];
		} else backtrack ( i + 1 );
	}
}

void toHop () {
	if ( k >= 0 && k <= n ) {
		a[0] = 0;
		backtrack ( 1 );
	}
}

int main () {
	int t; cin >> t;
	while ( t-- ) {
		cin >> n >> k;
		for ( int i = 0; i <= k; i++ ) {
			a[i] = 0;
			b[i] = 0;
			c[i] = 0;
		}
		for ( int i = 1; i <= k; i++ )
			cin >> b[i];
		toHop ();
		cout << k - ans << endl;
		ans = 0;
	}
	system ( "pause" );
}