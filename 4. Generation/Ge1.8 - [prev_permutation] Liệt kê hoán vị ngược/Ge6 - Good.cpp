/*
**generate_all_permutations_of_N_objects
*/

#include<bits/stdc++.h>
using namespace std;

int t, n, temp;
int x[1111111];

void init () { //cấu hình đầu tiên
	temp = n;
	for ( int i = 0; i < n; i++ ) {
		x[i] = temp;
		temp--;
	}
}

void display () { //In ra cấu hình hiện tại
	for ( int i = 0; i < n; i++ ) cout << x[i];
	cout << " ";
}

int main () {
	cin >> t;
	while ( t-- ) {
		cin >> n;
		init ();
		do {
			display ();
		} while ( prev_permutation ( x, x + n ) );
		cout << "\n";
	} system ( "pause" );
}