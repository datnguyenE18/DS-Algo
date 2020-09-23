#include<bits/stdc++.h>
using namespace std;

void swap ( double &x, double &y ) {
	double temp = x;
	x = y;
	y = temp;
}

void Nhap ( double *&a, int n ) {
	for ( int i = 0; i < n; i++ ) cin >> a[i];
}

void Xuat ( double *a, int n ) {
	for ( int i = 0; i < n; i++ ) cout << a[i] << " ";
	cout << endl;
}

void BubbleSort ( double *&a, int n ) { // Sắp xếp từ trên xuống
	for ( int i = 0; i < n; i++ ) {
		for ( int j = n - 1; j > i; j-- ) {
			if ( a[j] <= a[j - 1] ) swap ( a[j], a[j - 1] );
		}
	}
}

/*void BubbleSort ( double *&a, int n ) { // Sắp xếp từ dưới lên
	for ( int i = 0; i < n; i++ ) {
		for ( int j = 0; j < n - i - 1; j++ ) {
			if ( a[j] >= a[j - 1] ) swap ( a[j], a[j - 1] );
		}
	}
}*/

int main () {
	double *a;
	int n;

	cout << "Nhap n: "; cin >> n;
	a = new double[n];
	cout << "Nhap cac phan tu: "; Nhap ( a, n );
	cout << "Cac phan tu da nhap: "; Xuat ( a, n );
	BubbleSort ( a, n );
	cout << "Da sap xep: "; Xuat ( a, n );
}
