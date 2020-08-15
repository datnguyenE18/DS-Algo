#include <bits/stdc++.h> 
using namespace std;

void Eratosthenes(int n) {
	vector<bool> mark(n + 1, true);

	mark[0] = mark[1] = false;

	for ( int i = 2; i <= n; i++ )
		if ( mark[i] )
			for ( int j = i * 2; j <= n; j += i )
				mark[j] = false;

	for ( int i = 2; i <= n; i++ )
		if ( mark[i] )
			cout << i << " ";
	cout << endl;
}

int main() {
	int n, t; cin >> t;
	while ( t-- ) {
		cin >> n;
		Eratosthenes(n);
	}
}
