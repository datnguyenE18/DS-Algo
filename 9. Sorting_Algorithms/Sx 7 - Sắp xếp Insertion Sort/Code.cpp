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

void InsertionSort ( double *&a, int n ) {
	int pos; // Vị trí cần tìm
	double temp; //tạm lưu a[i]
	for ( int i = 0; i < n; i++ ) { // đoạn a[0] -> a[1] đã sắp xếp
		temp = a[i];
		pos = i - 1;
		//Tìm vị trí để chèn x vào phía trước:
		while ( ( pos >= 0 ) && ( a[pos] > temp ) ) {
			a[pos + 1] = a[pos]; // kết hợp dời vế sau
			pos--;
		} a[pos + 1] = temp;
	}
}

int main () {
	double *a;
	int n;

	cout << "Nhap n: "; cin >> n;
	a = new double[n];
	cout << "Nhap cac phan tu: "; Nhap ( a, n );
	cout << "Cac phan tu da nhap: "; Xuat ( a, n );
	InsertionSort ( a, n );
	cout << "Da sap xep: "; Xuat ( a, n );

	system ( "pause" );
}
