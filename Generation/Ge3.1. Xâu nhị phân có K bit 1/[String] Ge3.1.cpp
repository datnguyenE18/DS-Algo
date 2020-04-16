#include<bits/stdc++.h>
using namespace std;

int t, n, k;
string x;
bool check;


//First configuration
void first_conf () {
	for ( int i = 0; i < n; i++ ) {
		if ( i < n - k ) x += "0";
		else x += "1";
	}
}

//Next Bit Strings
void next_confs () {
	int i = n - 1;
	for ( ; i >= 0 && x[i] == '1'; i-- )  x[i] = '0';
	if ( i >= 0 ) x[i] = '1';
	else check = false;
}

//Print configuration
void display () {
	int dem = 0;
	for ( int i = 0; i < n; i++ ) {
		if ( x[i] == '1' ) dem++;
	}
	if ( dem == k ) cout << x << endl;
}

int main () {
	cin >> t;
	while ( t-- ) {
		x = "";
		check = true;
		cin >> n >> k;
		first_conf ();
		while ( check ) {
			display ();
			next_confs ();
		}
	} return 0;
}