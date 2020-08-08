#include<bits/stdc++.h>
using namespace std;
#define IOS() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define all(a) a.begin(), a.end()
typedef long long int ll;

int n;
vector<int> a;

void Input() {
	cin >> n;
	a.resize(n);
	for ( int i = 0; i < n; i++ ) cin >> a[i];
}

void Solve() {
	vector<pair<int, int>> b(n);
	for ( int i = 0; i < n; i++ ) {
		b[i].first = a[i];
		b[i].second = i;
	}
	sort(all(b));
	int ans = 0;
	for ( int i = 0; i < n; i++ ) {
		if ( b[i].second == i ) continue;
		else {
			swap(b[i].first, b[b[i].second].first);
			swap(b[i].second, b[b[i].second].second);
		}
		if ( i != b[i].second ) --i;
		ans++;
	}
	cout << ans << endl;
}

int main() {
	IOS()
	int test; cin >> test;
	while ( test-- ) {
		Input();
		Solve();
	}
}