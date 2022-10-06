#include<bits/stdc++.h>
#define MAX 102
using namespace std;

int n = 8, save[MAX], A[MAX][MAX], ans = 0;
bool col[MAX], right_dia[MAX], left_dia[MAX];

int calc () {
	int sum = 0;
	for ( int i = 1; i <= n; i++ )
		sum += A[i][save[i]];
	return sum;
}

void Try ( int i ) {
	for ( int j = 1; j <= n; j++ )
	if ( !( col[j] || right_dia[i - j + n] || left_dia[i + j - 1] ) ) {
		save[i] = j;
		col[j] = true;
		right_dia[i - j + n] = true;
		left_dia[i + j - 1] = true;
		if ( i == n )
			ans = max ( ans, calc () );
		else Try ( i + 1 );
		col[j] = false;
		right_dia[i - j + n] = false;
		left_dia[i + j - 1] = false;
	}
}

int main () {
	int t; cin >> t;
	while ( t-- ) {
		ans = 0;
		for ( int i = 1; i <= n; i++ ) {
			for ( int j = 1; j <= n; j++ )
				cin >> A[i][j];
		}
		Try ( 1 );
		cout << ans << "\n";
	} return 0;
}

/*
1
1 2 3 4 5 6 7 8
9 10 11 12 13 14 15 16
17 18 19 20 21 22 23 24
25 26 27 28 29 30 31 32
33 34 35 36 37 38 39 40
41 42 43 44 45 46 47 48
48 50 51 52 53 54 55 56
57 58 59 60 61 62 63 64
260
*/