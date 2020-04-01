#include <bits\stdc++.h>
using namespace std;

void solve ( string num ) {
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
	int t; cin >> t;
	string num;
	while ( t-- ) {
		cin >> num;
		solve ( num );
	} system ( "pause" );
}