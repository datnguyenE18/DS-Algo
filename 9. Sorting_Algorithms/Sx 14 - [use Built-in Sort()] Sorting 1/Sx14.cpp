// Sắp xếp + con trỏ
#include<bits/stdc++.h>
using namespace std;

const int maxN = 1e3 + 1;
int A[maxN], n;

void init() {
	cin >> n;
	for ( int i = 0; i < n; i++ )
		cin >> A[i];
}

void solve() {
	sort(A, A + n);
	int l = 0, r = n - 1; // left & right
	while ( l < r ) {
		cout << A[r] << " " << A[l] << " ";
		l++;
		r--;
	}
	if ( l == r ) cout << A[l];
	cout << endl;
}

int main() {
	int t; cin >> t;
	while ( t-- ) {
		init();
		solve();
	}
}