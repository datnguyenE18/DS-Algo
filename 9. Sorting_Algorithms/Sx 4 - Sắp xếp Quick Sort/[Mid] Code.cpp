#include<bits/stdc++.h>
using namespace std;

void Nhap ( double *&a, int n ) {
	for ( int i = 0; i < n; i++ ) cin >> a[i];
}

void Xuat ( double *a, int n ) {
	for ( int i = 0; i < n; i++ ) cout << a[i] << ",	";
	cout << endl;
}

void swap ( double &a, double &b ) {
	double temp = a;
	a = b;
	b = temp;
}

void QuickSort ( double *&a, int L, int R ) {
	double pivot = a[( L + R ) / 2];
	int i = L;
	int j = R;
	while ( i <= j ) {
		while ( a[i] < pivot ) i++;
		while ( a[j] > pivot ) j--;
		if ( i <= j ) {
			swap ( a[i], a[j] );
			i++;
			j--;
		}
	}
	if ( L < j ) QuickSort ( a, L, j );
	if ( i < R ) QuickSort ( a, i, R );
}

int main () {
	double *a;
	int n;
	cout << "Nhap do dai: "; cin >> n;
	a = new double[n];
	cout << "Nhap cac phan tu: "; Nhap ( a, n );
	cout << "Mang vua nhap: "; Xuat ( a, n );
	QuickSort ( a, 0, n - 1 );
	cout << "Mang da Sap xep: "; Xuat ( a, n );

	system ( "pause" );
}