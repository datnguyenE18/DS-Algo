#include <bits/stdc++.h>
using namespace std;

int n, a[1000], k,
C[1000][1000] = { 0 };
bool check[1000];
vector<string> v;

int Sum () {
	int sum = 0;
	for ( int i = 1; i <= n; i++ )
		sum += C[i][a[i]];
	return sum;
}

void Init () {
	for ( int i = 1; i <= n; i++ ) {
		a[i] = i;
		check[i] = true;
	}
}

void Display () {
	string s;
	for ( int i = 1; i <= n; i++ ) {
		s += ( char ) ( a[i] + '0' );
		s += ' ';
	}
	v.push_back ( s );
}

void Try ( int i ) {
	for ( int j = 1; j <= n; j++ ) {
		if ( check[j] ) {
			a[i] = j;
			check[j] = false;
			if ( i == n ) {
				if ( Sum () == k )
					Display ();
			} else Try ( i + 1 );
			check[j] = true;
		}
	}
}

void Solve () {
	cin >> n >> k;
	for ( int i = 1; i <= n; i++ ) {
		for ( int j = 1; j <= n; j++ )
			cin >> C[i][j];
	}
	Init ();
	Try ( 1 );
	cout << v.size () << endl;
	for ( int i = 0; i < n; i++ )
		cout << v[i] << endl;
}

int main () {
	Solve ();
	system ( "pause" );
}