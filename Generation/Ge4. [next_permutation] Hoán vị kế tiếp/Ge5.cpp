/*
**next_permutation
*/

#include<bits/stdc++.h>
using namespace std;

int t, n;
int x[111111];

void input () {
	for ( int i = 0; i < n; i++ ) cin >> x[i];
}

void output () {
	for ( int i = 0; i < n; i++ ) cout << x[i] << " ";
	cout << "\n";
}

int main () {
	cin >> t;
	while ( t-- ) {
		cin >> n;
		input ();
		next_permutation ( x, x + n );
		output ();
	} system ( "pause" );
}