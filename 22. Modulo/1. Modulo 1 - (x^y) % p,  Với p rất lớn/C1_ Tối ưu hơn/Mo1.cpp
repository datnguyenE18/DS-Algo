#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll calc(int x, int y, ll p) {
	if ( y == 0 ) return 1;
	ll tmp = calc(x, y / 2, p);
	tmp = tmp * tmp % p;
	if ( y % 2 ) tmp = tmp * x % p;
	return tmp;
}

// a^(b/2) % p = (a^(b/2) % p) * (a^(b/2) % p) 

int main() {
	int x, y, t; cin >> t;
	ll p;
	while ( t-- ) {
		cin >> x >> y >> p;
		cout << calc(x, y, p) << endl;
	}
}