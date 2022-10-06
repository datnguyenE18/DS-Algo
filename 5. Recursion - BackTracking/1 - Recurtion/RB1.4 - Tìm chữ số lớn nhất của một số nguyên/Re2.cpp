#include <bits/stdc++.h>
using namespace std;

int compare ( int a, int b ) {
	if ( a > b ) return a;
	return b;
}

int check ( int so ) {
	if ( so == 0 ) return 0;
	return compare ( so % 10, check ( so / 10 ) );
}

int main () {
	int t, so; cin >> t;
	while ( t-- ) {
		cin >> so;
		cout << check ( so ) << endl;
	} system ( "pause" );
}