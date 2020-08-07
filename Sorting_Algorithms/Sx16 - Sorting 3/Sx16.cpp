// Sắp xếp + tham lam
#include<bits/stdc++.h>
using namespace std;

const int maxN = 1e3 + 1;
pair<int, int> a[maxN];
int n, x;

void input() {
	cin >> n;
	for ( int i = 0; i < n; i++ ) {
		cin >> a[i].first;
		a[i].second = i;
	}
}

void solve() {
	sort(a, a + n);
	int ans = 0;
	int visit[n] = { 0 };
	for ( int i = 0; i < n; i++ ) {
		if ( visit[i] == 1 || a[i].second == i )
			continue;
		int cnt = 0;
		int j = i;
		while ( visit[j] == 0 ) {
			visit[j] = 1;
			j = a[j].second;
			cnt++;
		}
		if ( cnt > 0 ) ans += ( cnt - 1 );
	}
	cout << ans << '\n';
}

int main() {
	int t; cin >> t;
	while ( t-- ) {
		input();
		solve();
	}
}