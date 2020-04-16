#include <bits/stdc++.h>
using namespace std;
#define MAX 100
#define TRUE 1
#define FALSE 0

int t, n, k, X[MAX], dem = 0, OK = TRUE;

void Init () { 
	k = 1;
	X[k] = n;
}

void Display () {
	cout << "(";
	for ( int i = 1; i < k; i++ )
		cout << X[i] << " ";
	cout << X[k] << ") ";
}

void Next_Division () {
	int i = k, j, R, S, D;

	while ( i > 0 && X[i] == 1 ) i--;

	if ( i > 0 ) {
		X[i] = X[i]--; D = k - i + 1;
		R = D / X[i]; S = D % X[i];
		k = i;

		if ( R > 0 ) {
			for ( j = i + 1; j <= i + R; j++ )
				X[j] = X[i];
			k = k + R;
		}

		if ( S > 0 ) {
			k = k + 1;
			X[k] = S;
		}
	} else OK = 0;
}

int main () {
	cin >> t;
	while ( t-- ) {
		OK = true;
		cin >> n;
		Init ();

		while ( OK ) {
			Display ();
			Next_Division ();
		} cout << "\n";
	}system ( "pause" );
}