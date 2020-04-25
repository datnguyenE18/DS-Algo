
#include<bits/stdc++.h>
using namespace std;
vector<int> x ( 11 );
vector<vector<int> > v;
int a[11][11];
int n, k;
bool check[11];

bool checkSum () {
	int s = 0;
	for ( int i = 1; i <= n; i++ )
		s += a[i][x[i]];
	return ( s == k );
}

void qlHoanVi ( int i ) {
	for ( int j = 1; j <= n; j++ )
	if ( check[j] == false ) {
		x[i] = j;
		check[j] = true;
		if ( i == n ) {
			if ( checkSum () )
				v.push_back ( x );
		} else qlHoanVi ( i + 1 );
		check[j] = false;
	}
}

int main () {
	cin >> n >> k;
	for ( int i = 1; i <= n; i++ ) {
		for ( int j = 1; j <= n; j++ )
			cin >> a[i][j];
	}

	qlHoanVi ( 1 );
	cout << v.size () << endl;
	for ( int i = 0; i < v.size (); i++ ) {
		for ( int j = 1; j <= n; j++ )
			cout << v[i][j] << " ";
		cout << endl;
	}
	system ( "pause" );
}
