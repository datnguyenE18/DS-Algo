#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int Tprime ( ll n ) {
	int count = 0;
	for ( int i = 2; i <= sqrt ( n ); i++ ) {
		int temp = 0;
		for ( int j = 2; j <= sqrt ( i ); j++ ) {
			if ( i % j == 0 ) {
				temp = 1;
				break;
			}
		} if ( temp ) continue;
		count++;
	} return count;
}

int main () {
	ll n;
	int t;  cin >> t;
	while ( t-- ) {
		cin >> n;
		cout << Tprime ( n ) << endl;
	} system ( "pause" );
}