#include<bits/stdc++.h>
using namespace std;

int n, k, A[100];

void init() {
	cin >> n >> k;
	for ( int i = 0; i < n; i++ )
		cin >> A[i];
}

void solve() {
	sort(A, A + n);
	int count = 0;
	for ( int i = 0; i < n; i++ ) {
		if ( A[i] < k ) {
			for ( int j = i + 1; j < n; j++ ) {
				if ( A[j] <= k ) {
					if ( A[i] + A[j] == k )
						count++;
				} else break;
			}
		} else break;
	}
	cout << count << endl;
}

int main() {
	int t; cin >> t;
	while ( t-- ) {
		init();
		solve();
	}
}