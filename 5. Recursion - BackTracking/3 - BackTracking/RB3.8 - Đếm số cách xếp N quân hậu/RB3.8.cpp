#include<bits/stdc++.h>
using namespace std;

int n, count0 = 0;
bool col[100], right_dia[100], left_dia[100];

void Try ( int i ) {
	for ( int j = 1; j <= n; j++ ) {
		if ( !right_dia[i - j + n] && !left_dia[i + j - 1] && !col[j] ) {
			col[j] = true;
			right_dia[i - j + n] = true;
			left_dia[i + j - 1] = true;
			if ( i == n ) count0++;
			else Try ( i + 1 );

			col[j] = false;
			right_dia[i - j + n] = false;
			left_dia[i + j - 1] = false;
		}
	}
}

int main () {
	cin >> n;
	Try ( 1 );
	cout << count0 << "\n";
	return 0;
}

/*
4
2
*/