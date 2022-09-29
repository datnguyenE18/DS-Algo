#include <bits/stdc++.h>
#define maxn 60001
using namespace std;
int n;
int a[maxn], it[5 * maxn];
void update ( int r, int k, int l, int u, int v, int val ) {
	if ( v < k || l < u ) return;
	if ( u <= k&&l <= v ) { it[r] += val; return; }
	int g = ( k + l ) / 2;
	update ( 2 * r, k, g, u, v, val );
	update ( 2 * r + 1, g + 1, l, u, v, val );
	it[r] = it[2 * r] + it[2 * r + 1];
}
int get ( int r, int k, int l, int u, int v ) {
	if ( v < k || l < u ) return 0;
	if ( u <= k&&l <= v ) return it[r];
	int g = ( k + l ) / 2;
	int t1 = get ( 2 * r, k, g, u, v );
	int t2 = get ( 2 * r + 1, g + 1, l, u, v );
	return t1 + t2;
}
int main () {
	cin >> n;
	int m = 0;
	for ( int i = 1; i <= n; i++ ) {
		cin >> a[i];
		m = max ( m, a[i] );
	}
	int ds = 0;
	for ( int i = n; i >= 1; i-- ) {
		int t = get ( 1, 1, m, 1, a[i] - 1 );
		ds = ds + t;
		update ( 1, 1, m, a[i], a[i], 1 );
	}
	cout << ds;

	system ( "pause" );
	return 0;
}