#include<bits/stdc++.h>
using namespace std;

void solve(int n) {
	int exp = 0;

	while ( n % 2 == 0 ) {
		exp++;
		n /= 2;
	}

	if ( exp != 0 )
		cout << 2 << " " << exp << " ";

	for ( int i = 3; i <= n; i += 2 ) {
		exp = 0;
		while ( n % i == 0 ) {
			n /= i;
			exp++;
		}
		if ( exp != 0 )
			cout << i << " " << exp << " ";
	}
	cout << endl;
}

int main() {
	int t, n; cin >> t;
	while ( t-- ) {
		cin >> n;
		solve(n);
	}
}