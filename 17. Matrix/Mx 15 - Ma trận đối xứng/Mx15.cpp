#include<bits/stdc++.h>
using namespace std;

int t, n, x[111][111];

void input () {
	for ( int i = 0; i < n; i++ )
	for ( int j = 0; j < n; j++ )
		cin >> x[i][j];
}

int solve () {
	for ( int i = 0; i < n; i++ ) {
		for ( int j = 0; j < n; j++ ) {
			if ( x[i][j] != x[j][i] ) return 0;
		}
	} return 1;
}

int main () {
	cin >> t;
	while ( t-- ) {
		cin >> n;
		input ();
		if ( solve () ) cout << 1 << endl;
		else cout << 0 << endl;
	} system ( "pause" );
}