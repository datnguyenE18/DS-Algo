/*
**generate_all_permutations_of_N_objects
*/

#include<bits/stdc++.h>
using namespace std;

int t, n;
int x[1111111];

void init () { //cấu hình đầu tiên
	for ( int i = 0; i < n; i++ ) x[i] = i + 1;
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
		} while ( next_permutation ( x , x + n) );
		cout << "\n";
	} system ( "pause" );
}