#include <bits/stdc++.h>
using namespace std;

int n;
bool a[1000000];

void show () {
	for ( int i = 1; i <= n; i++ )
	if ( a[i] )
		cout << i;
	cout << endl;
}

void bt ( int u ) {
	if ( u == n + 1 ) {
		show ();
		return;
	}
	a[u] = 0;
	bt ( u + 1 );
	a[u] = 1;
	bt ( u + 1 );
}

int main () {
	cin >> n;
	bt ( 1 );

	system ( "pause" );
}