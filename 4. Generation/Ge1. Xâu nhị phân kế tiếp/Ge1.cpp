/*
**Next Bits String
*/

#include <bits/stdc++.h>
using namespace std;

int t;
string num;

void solve () {
	int i = num.size () - 1;
	for ( ; i >= 0; i-- ) {
		if ( num[i] == '1' ) num[i] = '0';
		else {
			num[i] = '1';
			cout << num << endl;
			return;
		}
		if ( i == 0 ) cout << num << endl;
	}
}

int main () {
	cin >> t;
	while ( t-- ) {
		cin >> num;
		solve ();
	} system ( "pause" );
}