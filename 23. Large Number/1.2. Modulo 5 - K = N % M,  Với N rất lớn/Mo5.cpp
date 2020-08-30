#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

void solve(string s, ll m) {
	ll res = 0;
	for ( int i = 0; i < s.size(); i++ )
		res = ( res * 10 + s[i] - '0' ) % m;
	cout << res << endl;
}

int main() {
	int t; cin >> t;
	string n;
	ll m;
	while ( t-- ) {
		cin >> n;
		cin >> m;
		solve(n, m);
	}
}