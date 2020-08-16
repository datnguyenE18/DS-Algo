#include <bits/stdc++.h> 
using namespace std;

int n, t;

void Eratosthenes(int n, vector<bool>mark) {
	for ( int i = 2; i <= sqrt(n); i++ )
		if ( mark[i] )
			for ( int j = i * i; j <= n; j += i )
				mark[j] = false;
}

int minMesure(int k, vector<bool>mark) {
	for ( int i = 3; i <= n; i++ )
		if ( mark[i] && ( k % i == 0 ) )
			return i;
}

void solve() {
	vector<bool> mark(n + 1, true);
	Eratosthenes(n, mark);
	for ( int i = 1; i <= n; i++ ) {
		if ( i == 1 || i == 2 )
			cout << i << " ";
		else if ( i % 2 == 0 )
			cout << 2 << " ";
		else
			cout << minMesure(i, mark) << " ";
	}
	cout << endl;
}

int main() {
	cin >> t;
	while ( t-- ) {
		cin >> n;
		solve();
	}
}
