/*
**Next_binary_strings
*/

#include<bits/stdc++.h>
using namespace std;

void nextBit(string bit) {
	for ( int i = bit.length() - 1; i >= 0; i-- ) {
		if ( bit[i] == '1' ) bit[i] = '0';
		else {
			bit[i] = '1';
			break;
		}
	}
	cout << bit << endl;
}

int main() {
	int t; cin >> t;
	string bit;
	while ( t-- ) {
		cin >> bit;
		nextBit(bit);
	}
}