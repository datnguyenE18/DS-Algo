#include <bits/stdc++.h>
using namespace std;

int temp = 0;

int count ( int so ) {
	if ( so == 0 ) return temp;
	temp++;
	return count ( so / 10 );
}

int main () {
	int t, so; cin >> t;
	while ( t-- ) {
		cin >> so;
		cout << count ( so ) << endl;
	} system ( "pause" );
}