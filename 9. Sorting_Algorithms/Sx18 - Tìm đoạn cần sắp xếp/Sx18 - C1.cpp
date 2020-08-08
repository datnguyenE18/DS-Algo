#include<bits/stdc++.h>
using namespace std;

const int maxN = 1e6 + 1;
int A[maxN], temp[maxN], n;

void init() {
	cin >> n;
	for ( int i = 0; i < n; i++ ) {
		cin >> A[i];
		temp[i] = A[i];
	}
}

void solve() {
	sort(A, A + n);

	for ( int i = 0; i < n; i++ ) {
		if ( A[i] != temp[i] ) {
			cout << i + 1 << " ";
			break;
		}
	}

	for ( int i = n - 1; i >= 0; i-- ) {
		if ( A[i] != temp[i] ) {
			cout << i + 1 << endl;
			break;
		}
	}
}

int main() {
	int t; cin >> t;
	while ( t-- ) {
		init();
		solve();
	}
}