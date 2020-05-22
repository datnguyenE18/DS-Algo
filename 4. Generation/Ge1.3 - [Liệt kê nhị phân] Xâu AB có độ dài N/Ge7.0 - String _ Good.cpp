#include<bits/stdc++.h>
using namespace std;

int n, tmp;
string bit;

void init() {
	cin >> n;
	bit.clear();
	tmp = pow(2, n) - 1;
	for ( int i = 0; i < n; i++ )
		bit += 'A';
	cout << bit << " ";
}

void nextBit() {
	for ( int i = n - 1; i >= 0; i-- ) {
		if ( bit[i] == 'B' ) bit[i] = 'A';
		else {
			bit[i] = 'B';
			break;
		}
	}
	cout << bit << " ";
}

int main() {
	int t; cin >> t;
	while ( t-- ) {
		init();
		while ( tmp-- )
			nextBit();
		cout << "\n";
	}
}