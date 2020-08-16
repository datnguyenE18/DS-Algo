#include <bits/stdc++.h> 
using namespace std;

void Eratosthenes(int m, int n) {
	vector<bool>mark(n + 1, true);
	mark[0] = mark[1] = false;

	for ( int i = 2; i <= sqrt(n); i++ )
		if ( mark[i] )
			for ( int j = i * i; j <= n; j += i )
				mark[j] = false;

	for ( int i = m; i <= n; i++ )
		if ( mark[i] )
			cout << i << " ";
	cout << endl;
}

int main() {
	int m, n, t;
	cin >> t;
	while ( t-- ) {
		cin >> m >> n;
		Eratosthenes(m, n);
	}
}
