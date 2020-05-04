#include<bits/stdc++.h>
using namespace std;
#define MAX 100

void Result ( int A[], int n ) {
	cout << "[";
	for ( int i = 0; i < n; i++ ) {
		if ( i == n - 1 ) cout << A[i];
		else cout << A[i] << " ";
	}
	cout << "]\n";
}

void Triangle ( int A[], int n ) {
	if ( n < 1 )
		return;
	int temp[n - 1];
	for ( int i = 0; i < n - 1; i++ ) {
		int x = A[i] + A[i + 1];
		temp[i] = x;
	}
	Triangle ( temp, n - 1 );
	Result ( A, n );
}

void Triangle1 ( int A[], int n ) {
	if ( n < 1 ) return;
	else {
		Result ( A, n ); int temp[n - 1];
		for ( int i = 0; i < n - 1; i++ ) {
			int x = A[i] + A[i + 1];
			temp[i] = x;
		}
		Triangle1 ( temp, n - 1 );
	}
}

int main ( ) {
	int T, A[MAX], n; cin >> T;
	while ( T-- ) {
		cin >> n;
		for ( int i = 0; i < n; i++ )
			cin >> A[i];
		Triangle1 ( A, n );
	}
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


