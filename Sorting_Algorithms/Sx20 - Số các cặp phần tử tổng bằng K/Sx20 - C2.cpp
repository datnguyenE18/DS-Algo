/*
	chất nhị phân ,
	l = vị trí đầu tiên lớn hơn hoặc bằng x - a[i].
	r = vi tri đầu tiên lớn hơn x - a[i].

*/

#include<bits/stdc++.h>
using namespace std;

typedef long long i64;
i64 n, x;
vector < int > a;

void input() {
	cin >> n >> x;
	a.resize(n);
	for ( int i = 0; i < n; i++ )
		cin >> a[i];
}

void solve() {
	long long res = 0;
	sort(a.begin(), a.end());

	for ( int i = 0; i < n; i++ ) {
		int l = lower_bound(a.begin() + i + 1, a.end(), x - a[i]) - a.begin();
		int r = upper_bound(a.begin() + i + 1, a.end(), x - a[i]) - a.begin();
		res += 1LL * ( r - l );
	}
	cout << res << endl;
}

int main() {
	int t = 1;
	cin >> t;
	while ( t-- ) {
		input();
		solve();
	}
}