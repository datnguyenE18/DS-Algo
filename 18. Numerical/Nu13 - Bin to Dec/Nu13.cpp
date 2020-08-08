#include<bits/stdc++.h>
using namespace std;

string bin;

int Bin_to_Dec () {
	int n = 0;
	for ( int i = 0; i < 32 && bin[i]; i++ ) {
		n <<= 1;
		if ( bin[i] == '1' )
			n |= 1;
	} return n;
}

int main () {
	cin >> bin;
	cout << Bin_to_Dec () << "\n";
	system ( "pause" );
}