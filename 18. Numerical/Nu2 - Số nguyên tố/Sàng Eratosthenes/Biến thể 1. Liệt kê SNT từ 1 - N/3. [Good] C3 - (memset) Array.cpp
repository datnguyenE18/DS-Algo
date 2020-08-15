#include <bits/stdc++.h> 
using namespace std;

void Eratosthenes(int n) {
	bool mark[n + 1];
	memset(mark, true, sizeof(mark));

	for ( int i = 2; i * i <= n; i++ )
		if ( mark[i] )
			for ( int j = i * i; j <= n; j += i )
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
