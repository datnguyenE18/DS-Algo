#include <bits/stdc++.h>
using namespace std;

void print_gray ( string binary ) {
	string shift = "0", gray = "";
	shift += binary;
	for ( int i = 0; i < binary.length (); i++ ) {
		if ( binary[i] != shift[i] ) gray += "1";
		else gray += "0";
	} 
	cout << gray << " ";
}

void bitString ( int x, string prefix ) {
	if ( x == 0 ) print_gray ( prefix );

	else {
		bitString ( x - 1, ( prefix + "0" ) );
		bitString ( x - 1, ( prefix + "1" ) );
	}
}

int main () {
	int n, t; cin >> t;

	while ( t-- ) {
		cin >> n;
		bitString ( n, "" );
		cout << "\n";
	} system ( "pause" );
}