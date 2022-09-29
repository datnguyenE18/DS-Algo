#include<bits/stdc++.h>
using namespace std;

int par[10] = { 500, 1000, 2000, 5000, 10000, 20000, 50000, 100000, 200000, 500000 };
int money, t;

void exchag () {
	for ( int i = 9; i >= 0; i-- ) {
		if ( int count = money / par[i] ) {
			cout << "(" << count << ")-" << par[i] << " ";
			money = money % par[i];
		}
	} cout << "\n";
}

int main () {
	cin >> t;
	while ( t-- ) {
		cin >> money;
		exchag ();
	} system ( "pause" );
}