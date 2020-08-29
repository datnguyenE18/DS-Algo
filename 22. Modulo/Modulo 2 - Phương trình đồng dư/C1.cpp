#include<bits/stdc++.h>
using namespace std;

void solve(int a, int m) {
	//a %= m;
	for ( int i = 1; i < m; i++ ) {
		if ( ( a * i ) % m == 1 ) {
			cout << i << endl;
			return;
		}
	}
	cout << -1 << endl;
}

int main() {
	int a, m, t; cin >> t;
	while ( t-- ) {
		cin >> a >> m;
		solve(a, m);
	}
}

