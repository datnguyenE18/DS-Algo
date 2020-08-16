#include <bits/stdc++.h> 
using namespace std;

void Solution(int n) {
	for ( int i = 1; i <= n; i++ ) {
		if ( i == 0 || i == 1 ) cout << 1 << " ";
		else if ( i % 2 == 0 ) cout << 2 << " ";
		else {
			for ( int j = 3; j < i; j++ ) {
				if ( i % j == 0 ) {
					cout << j << " ";
					break;
				}
			}
		}
	} cout << endl;
}

int main() {
	int T, n; cin >> T;
	while ( T-- ) {
		cin >> n;
		Solution(n);
	}
}
