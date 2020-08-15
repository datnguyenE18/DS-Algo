#include <bits/stdc++.h> 
typedef long long int ll;
using namespace std;

void Solution(ll n) {
	//Buoc 1: in ra uoc so 2 
	while ( n % 2 == 0 ) {
		cout << 2 << " ";
		n = n / 2;
	}

	//Buoc 2: dua ra cac uoc so le      
	for ( ll i = 3; i <= sqrt(n); i = i + 2 ) {
		// dua ra cac uoc so le
		while ( n % i == 0 ) {
			cout << i << " ";
			n = n / i;
		}
	}

	//Buoc 3: in ra so cuoi cung
	if ( 2 < n )
		cout << n << " " << endl;
}

int main(void) {
	int T; cin >> T;
	ll n;
	while ( T-- ) {
		cin >> n;
		Solution(n);
	}
}
