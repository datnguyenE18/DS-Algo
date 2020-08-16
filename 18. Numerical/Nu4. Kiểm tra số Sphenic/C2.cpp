#include<bits/stdc++.h>
using namespace std;

int Solving(int n) {
	int dem1 = 0, dem3 = 0;
	if ( n < 30 ) return dem1;
	else {
		while ( n % 2 == 0 ) {
			n /= 2;
			dem1++;
			dem3++;
		}
		if ( dem1 > 1 ) return 0;
		else {
			for ( int i = 3; i <= n; i += 2 ) {
				if ( n % i == 0 ) dem3++;
				while ( n % i == 0 ) {
					n /= i;
					dem1++;
				}
			}
			if ( dem1 != 3 || dem3 != 3 ) return 0;
			else return 1;
		}
	}
}

int main() {
	int n, T; cin >> T;
	while ( T-- ) {
		cin >> n;
		cout << Solving(n) << endl;
	} 
}