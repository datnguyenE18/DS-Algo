#include <bits/stdc++.h> 
using namespace std;

bool Solution(int n) {
	int odd = 0, even = 0, total = 0;

	while ( n % 2 == 0 ) {
		even++; total++;
		if ( even > 1 ) return false;
		n /= 2;
	}

	for ( int i = 3; i <= sqrt(n); i = i + 2 ) {
		even = 0;
		while ( n % i == 0 ) {
			total++; even++;
			if ( even > 1 ) return false;
			n /= i;
		}
	}

	if ( n > 1 ) total++;
	return( total == 3 );
}

int main() {
	int T, n; cin >> T;
	while ( T-- ) {
		cin >> n;
		cout << Solution(n) << endl;
	}
}
