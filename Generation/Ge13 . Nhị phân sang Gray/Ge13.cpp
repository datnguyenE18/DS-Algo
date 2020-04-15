#include <bits/stdc++.h>
using namespace std;

int t;
string binary;

void print_gray () {
	string shift = "0", gray = "";
	shift += binary;
	for ( int i = 0; i < binary.length (); i++ ) {
		if ( binary[i] != shift[i] ) gray += "1";
		else gray += "0";
	}
	cout << gray << endl;
}

int main () {
	cin >> t;
	while ( t-- ) {
		cin >> binary;
		print_gray ();
	} system ( "pause" );
}