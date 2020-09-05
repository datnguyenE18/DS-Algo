#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solution(ll b, ll p) {
	ll res = 0;
	for ( ll i = 1; i < p; i++ ) {
		if ( ( i * i ) % p == 1 ) {
			ll last = i + p * ( b / p );
			if ( last > b )
				last -= p;
			res += ( ( last - i ) / p + 1 );
		}
	}
	cout << res << endl;
}

int main() {
	int t; cin >> t;
	ll b, p;
	while ( t-- ) {
		cin >> b >> p;
		solution(b, p);
	}
}