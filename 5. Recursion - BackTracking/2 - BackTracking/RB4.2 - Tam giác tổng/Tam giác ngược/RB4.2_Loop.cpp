#include<bits/stdc++.h>
using namespace std;

vector<int> A[100];
int n, temp;

void dis_result ( ) {
	cout << "[";
	for ( int i = 1; i <= n; i++ ) {
		for ( int j = 0; j < A[i].size ( ); j++ ) {
			if ( j == A[i].size ( ) - 1 ) cout << A[i][j] << "]\n";
			else cout << A[i][j] << " ";
		}
	}
}

void imp_A () {
	for ( int i = 1; i <= n; i++ ) {
		cin >> temp;
		A[n].push_back ( temp );
	} dis_result ();
}

void Triangle () {
	while ( n >= 1 ) {
		n--;
		for ( int i = 0; i < A[n + 1].size () - 1; i++ ) {
			temp = A[n + 1][i] + A[n + 1][i + 1];
			A[n].push_back ( temp );
		} dis_result ();
	}
}

int main () {
	int t; cin >> t;
	while ( t-- ) {
		cin >> n;
		imp_A ();
		Triangle ();
	}
	return 0;
}

/*
1
5
1 2 3 4 5
[1 2 3 4 5]
[3 5 7 9]
[8 12 16]
[20 28]
[48]
*/