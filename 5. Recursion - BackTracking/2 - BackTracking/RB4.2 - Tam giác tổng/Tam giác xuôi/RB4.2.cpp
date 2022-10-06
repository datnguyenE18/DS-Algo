#include<bits/stdc++.h>
using namespace std;
#define ONLINE_JUDGE "ONLINE_JUDGE"
#define setIO() ios::sync_with_stdio(false); cin.tie(0);
#define all(a) a.begin(),a.end()

int test = 1, MULTI_TEST = 1, n;
vector < int > a;
vector < vector<int> > res;

void Try(vector < int > b) {
	vector < int > c;
	res.push_back(b);
	for ( int i = 0; i < b.size() - 1; i++ )
		c.push_back(b[i] + b[i + 1]);
	if ( c.size() != 0 ) Try(c);
}

void init() {
	cin >> n; a.resize(n); res.clear();
	for ( int i = 0; i < n; i++ )
		cin >> a[i];
}

void solve() {
	Try(a);
	for ( int i = res.size() - 1; i >= 0; i-- ) {
		cout << '[';
		for ( int j = 0; j < res[i].size() - 1; j++ )
			cout << res[i][j] << ' ';
		cout << res[i].back() << ']' << "\n";
	}
	cout << '\n';
}

int main() {
	setIO();
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	if ( MULTI_TEST == 1 ) cin >> test;
	for ( int i = 1; i <= test; i++ ) {
		init();
		solve();
}
}

/*
1
5
1 2 3 4 5

[48]
[20 28]
[8 12 16]
[3 5 7 9]
[1 2 3 4 5]
*/