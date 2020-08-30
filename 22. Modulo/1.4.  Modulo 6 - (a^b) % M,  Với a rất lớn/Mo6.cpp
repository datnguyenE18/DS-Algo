// (a^b) % M
#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(string a, ll b, ll M, ll newA) {
	ll res = 1;

	for ( int i = 0; i < a.length(); i++ ) {
		newA = newA * 10 + ( a[i] - 48 );
		newA %= M;
	}

	while ( b > 0 ) {
		if ( b & 1 )						//Nếu b là số lẻ thì nhân a với res
			res = ( res * newA ) % M;
		b = b >> 1;							// b = b / 2
		newA = ( newA * newA ) % M;
	}
	cout << res << endl;
}

int main() {
	int t; cin >> t;

	while ( t-- ) {
		string a;
		ll b, M, newA = 0;
		cin >> a >> b >> M;
		solve(a, b, M, newA);
	}
}