/*
	nhập vào 1 string để đếm chữ số cho nhanh.
	Đếm chữ số + sắp xếp + tham lam.
*/
#include<bits/stdc++.h>
using namespace std;

const int maxN = 1e7 + 1;
int n;
string a[maxN];

void init() {
	cin >> n;
	for ( int i = 0; i < n; i++ )
		cin >> a[i];
}

void solve() {
	int cnt[10] = { 0 };

	for ( int i = 0; i < n; i++ ) {
		for ( int j = 0; j < a[i].length(); j++ ) {
			int x = a[i][j] - '0';
			cnt[x]++;
		}
	}

	for ( int i = 0; i < 10; i++ )
		if ( cnt[i] != 0 )
			cout << i << ' ';
	cout << endl;
}

int main() {
	int t = 1;
	cin >> t;
	while ( t-- ) {
		init();
		solve();
	}
}