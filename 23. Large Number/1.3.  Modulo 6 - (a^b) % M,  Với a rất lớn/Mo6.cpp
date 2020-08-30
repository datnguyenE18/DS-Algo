// (a^b) % M
#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(string a, ll b, ll M) {
	ll res = 1,
		mod = 0;

	for ( int i = 0; i < a.length(); i++ )
		mod = ( mod * 10 + a[i] - '0' ) % M;

	while ( b > 0 ) {
		if ( b & 1 )						//Nếu b là số lẻ thì nhân a với res
			res = ( res * mod ) % M;
		b = b >> 1;							// b = b / 2
		mod = ( mod * mod ) % M;
	}
	cout << res << endl;
}

int main() {
	int t; cin >> t;

	while ( t-- ) {
		string a;
		ll b, M;
		cin >> a >> b >> M;
		solve(a, b, M);
	}
}