#include <bits/stdc++.h> 
using namespace std;
#define MAX 100000 

int UCLN2So ( int x, int y ) {
	if ( x % y == 0 ) return y;
	return UCLN2So ( y, x % y );
}

int UCLN ( int a[], int n ) {
	int UCLN = a[0];
	for ( int i = 1; i < n; i++ ) UCLN = UCLN2So ( UCLN, a[i] );
	return UCLN;
}

int tich ( int a[], int n ) {
	int tich = 1;
	for ( int i = 0; i < n; i++ ) tich *= a[i];
	return tich;
}

int multiply ( int x, int res[], int res_size ) {
	int carry = 0;
	for ( int i = 0; i < res_size; i++ ) {
		int prod = res[i] * x + carry;
		res[i] = prod % 10;
		carry = prod / 10;
	}
	while ( carry ) {
		res[res_size] = carry % 10;
		carry = carry / 10;
		res_size++;
	} return res_size;
}

void power ( int x, int n ) {
	if ( n == 0 ) {
		cout << "1";
		return;
	}
	int res[MAX];
	int res_size = 0;
	int temp = x;

	while ( temp != 0 ) {
		res[res_size++] = temp % 10;
		temp = temp / 10;
	}
	for ( int i = 2; i <= n; i++ ) 	res_size = multiply ( x, res, res_size );
	for ( int i = res_size - 1; i >= 0; i-- ) cout << res[i];
}

void Nhap_Mang ( int *a, int n ) {
	for ( int i = 0; i < n; i++ ) cin >> a[i];
}

int main () {
	int *a;
	int n, T; cin >> T;
	while ( T-- ) {
		cin >> n;
		a = new int[n];
		Nhap_Mang ( a, n );

		int gx = UCLN ( a, n );
		int hx = tich ( a, n );
		power ( hx, gx );
		delete[] a;
	}
	system ( "pause" );
	return 0;
}