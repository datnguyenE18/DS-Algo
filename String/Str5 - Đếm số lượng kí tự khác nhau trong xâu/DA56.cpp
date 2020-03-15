#include<bits/stdc++.h>
using namespace std;

bool check ( string s, int n ) {
	for ( int i = 0; i < n; i++ ) {
		if ( s[i] == s[n] ) return false;
	} return true;
}

int differentSymbolsNaive ( string s ) {
	int  dem = 1;
	for ( int i = 1; i <= s.size () - 1; i++ ) {
		if ( check ( s, i ) ) dem++;
		else continue;
	} return dem;
}


int main () {
	string s;
	getline ( cin, s );
	cout << differentSymbolsNaive ( s );

	system ( "pause" );
}