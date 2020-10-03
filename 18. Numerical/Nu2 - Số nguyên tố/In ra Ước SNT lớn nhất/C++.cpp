#include <bits/stdc++.h> 
typedef long long int ll;
using namespace std;

void solve(ll n) {
	ll temp = 0;
	while ( n % 2 == 0 ) {
		temp = 2;
		n /= 2;
	}

	for ( ll i = 3; i <= sqrt(n); i += 2 ) {
		while ( n % i == 0 ) {
			temp = i;
			n /= i;
		}
	}

	if ( n > 2 ) temp = n;
	cout << temp << endl;
}

int main() {
	int t; cin >> t;
	ll n;
	while ( t-- ) {
		cin >> n;
		solve(n);
	}
}
