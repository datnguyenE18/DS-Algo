#include<bits/stdc++.h>
using namespace std;

const int maxN = 1e3 + 1;
int n, A[maxN];
vector<int> temp;

void init() {
	cin >> n;
	temp.resize(n);
	for ( int i = 0; i < n; i++ ) {
		cin >> A[i];
		temp.push_back(A[i]);
	}
}

void solve() {
	int count = 0;
	for ( int i = 0; i < n; i++ )
		if ( A[i] != temp[i] )
			count++;
	cout << count / 2 << endl;
}

int main() {
	int t; cin >> t;
	while ( t-- ) {
		init();
		solve();
	}
}