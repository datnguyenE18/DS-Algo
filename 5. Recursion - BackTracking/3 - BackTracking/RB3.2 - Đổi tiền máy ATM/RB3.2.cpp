#include <bits/stdc++.h>
using namespace std;

int n, S, a[100], ans = 1e9 + 7;
bool unVis[100];
long long tong = 0;

void Try ( int i, int Sum ) {
	if ( Sum<0 ) return;
	if ( Sum>tong ) return;
	if ( i >= ans ) return;
	for ( int j = 1; j <= n; j++ ) {
		if ( unVis[j] ) {
			unVis[j] = false;
			Sum -= a[j];
			tong -= a[j];
			if ( Sum == 0 ) {
				ans = min ( ans, i );
			} else {
				Try ( i + 1, Sum );
			}
			Sum += a[j];
			tong += a[j];
			unVis[j] = true;
		}
	}
}

void Solve () {
	cin >> n >> S;
	for ( int i = 1; i <= n; i++ ) {
		cin >> a[i];
		tong += a[i];
		unVis[i] = true;
	}
	Try ( 1, S );
	if ( ans == 1e9 + 7 ) cout << "-1";
	else cout << ans << endl;
}

int main () {
	Solve ();
	system ( "pause" );
}