#include<bits/stdc++.h>
using namespace std;

int t;
string Binary;

void Bin_to_Gray () {
	cin >> Binary;
	for ( int i = 0; i < Binary.length (); i++ ) {
		if ( i == 0 ) cout << Binary[i];
		else {
			if ( Binary[i] != Binary[i - 1] ) cout << "1";
			else cout << "0";
		}
	} cout << "\n";
}

int main () {
	cin >> t;
	while ( t-- ) {
		Bin_to_Gray ();
	} system ( "pause" );
}