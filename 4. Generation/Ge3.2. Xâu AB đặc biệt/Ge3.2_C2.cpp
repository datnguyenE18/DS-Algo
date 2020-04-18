#include<bits/stdc++.h>
using namespace std;
#define M 100

int n, k, d = 0;
vector<vector<int> > v;
vector<int> x;

void Update () {
	v.push_back ( x );
	d++;
}

void res () {
	for ( int i = v.size () - 1; i >= 0; i-- ) {
		for ( int j = 0; j < v.at ( i ).size (); j++ ) {
			if ( v.at ( i ).at ( j ) == 1 ) cout << "A";
			else cout << "B";
		} cout << endl;
	}
}

bool Check () {
	int t = 0, dem = 0;
	for ( int i = 0; i <= n - 1; i++ ) {
		if ( x.at ( i ) == 1 ) t++;
		else t = 0;
		if ( t > k ) return false;
		else if ( t == k ) dem++;
	} return ( dem == 1 );
}

void qlNhiPhan ( int i ) {
	for ( int j = 0; j <= 1; j++ ) {
		x.at ( i ) = j;
		if ( i == n - 1 ) {
			if ( Check () )	Update ();
		} else qlNhiPhan ( i + 1 );
	}
}

int main () {
	cin >> n >> k;
	x.resize ( n );
	qlNhiPhan ( 0 );
	cout << d << endl;
	res ();
	system ( "pause" );
}
