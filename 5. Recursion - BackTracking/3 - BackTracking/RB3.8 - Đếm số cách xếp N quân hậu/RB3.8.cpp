#include<bits/stdc++.h>
using namespace std;
#define MAX 100

int n,
	dem,
	col[MAX], //Kiểm tra cột
	right_dia[2 * MAX], //Kiểm tra đường chéo phải
	left_dia[2 * MAX]; //Kiểm tra đường chéo trái

void Init () {
	dem = 0;
	for ( int j = 1; j <= n; j++ )
		col[j] = 1;

	for ( int k = 1; k <= 2 * n - 1; k++ ) {
		right_dia[k] = 1;
		left_dia[k] = 1;
	}
}

void Try ( int i ) {
	for ( int j = 1; j <= n; j++ ) {
		if ( right_dia[i - j + n] && left_dia[i + j - 1] && col[j] ) {
			col[j] = 0;
			right_dia[i - j + n] = 0;
			left_dia[i + j - 1] = 0;
			if ( i == n ) dem++;
			else Try ( i + 1 );

			col[j] = 1;
			right_dia[i - j + n] = 1;
			left_dia[i + j - 1] = 1;
		}
	}
}


int main () {
	cin >> n;
	Init ();
	Try ( 1 );
	cout << dem << "\n";
	return 0;
}
