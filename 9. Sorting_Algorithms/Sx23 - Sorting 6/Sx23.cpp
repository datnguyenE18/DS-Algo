#include<bits/stdc++.h>
using namespace std;

const int maxN = 1e5 + 5;
int a[maxN], n;

void input() {
	cin >> n;
	for ( int i = 0; i < n; i++ )
		cin >> a[i];

}

void solve() {
	sort(a, a + n);
	for ( int i = 0; i < n; i++ )
		cout << a[i] << ' ';
	cout << endl;
}

int main() {
	int t; cin >> t;
	while ( t-- ) {
		input();
		solve();
	}
}