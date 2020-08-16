#include <bits/stdc++.h> 
using namespace std;

void Eratosthenes(int n) {
	vector<bool>mark(n + 1, true);

	for ( int i = 2; i <= sqrt(n); i++ )
		if ( mark[i] )
			for ( int j = i * i; j <= n; j += i )
				mark[j] = false;

	for ( int i = 2; i <= n / 2; i++ ) {
		int temp = n - i;
		if ( mark[i] && mark[temp] ) {
			cout << i << " " << temp << endl;
			break;
		}
	}
}

int main() {
	int n, t;
	cin >> t;
	while ( t-- ) {
		cin >> n;
		Eratosthenes(n);
	}
}
