/*
**Generate all the binary strings of N bits
*/

#include<bits/stdc++.h>
using namespace std;
#define MAX 11111

int t, n, x[MAX];
bool check;


//First configuration
void first_conf () {
	for ( int i = 0; i < n; i++ ) x[i] = 0;
}

//Next Bit Strings
void next_confs () {
	int i = n - 1;
	for ( ; i >= 0 && x[i] == 1; i-- )  x[i] = 0;
	if ( i >= 0 ) x[i] = 1;
	else check = false;
}

//Print configuration
void display () {
	for ( int i = 0; i < n; i++ ) cout << x[i] << " ";
	cout << "\n";
}

int main () {
	cin >> t;
	while ( t-- ) {
		check = true;
		cin >> n;
		first_conf ();
		while ( check ) {
			display ();
			next_confs ();
		}
	} system ( "pause" );
}