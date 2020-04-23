/*
**Next_binary_strings
*/

#include<bits/stdc++.h>
using namespace std;
#define MAX 11111

int t;
char x[MAX];

void Next_Bits_String () {
	int n = strlen ( x );
	int i = n - 1;
	for ( ; i >= 0 && x[i] == '1'; i-- ) {
		x[i] = '0';
	}
	if ( i >= 0 ) x[i] = '1';
}

int main () {
	cin >> t;
	while ( t-- ) {
		cin >> x;
		Next_Bits_String ();
		cout << x << endl;
	} system ( "pause" );
}
