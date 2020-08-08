#include<bits/stdc++.h>
#define faster() ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
typedef long long i64;

int n, s;
vector < int > a;

void init() {
	cin >> n >> s; a.resize(n);
	for ( int i = 0; i < n; i++ )
		cin >> a[i];
}

void solve() {
	sort(a.begin(), a.end());
	int res = 0;
	for ( int i = n - 1; i >= 0; i-- ) {
		if ( s > a[i] ) {
			int tmp = s / a[i];
			s -= tmp * a[i];
			res += tmp;
		}
	}
	cout << res;
}

int main() {
	faster();
	int t = 1; cin >> t;
	while ( t-- ) {
		init();
		solve();
	}
	//cerr << "\nRunning is : " << 1.0 * clock() / 1000;
}