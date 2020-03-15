#include<bits/stdc++.h>
using namespace std;

// Hàm đổi chỗ
void Swap ( double &a, double &b ) {
	double temp = a;
	a = b;
	b = temp;
}

//Hàm nhập mảng
void NhapMang ( double *&a, int n ) {
	cout << "Nhap gia tri cac phan tu: " << endl;
	for ( int i = 0; i < n; i++ ) {
		cout << "a[" << i << "] = "; cin >> a[i];
	}
}

//Hàm xuất mảng
void XuatMang ( double *a, int n ) {
	for ( int i = 0; i < n; i++ ) {
		cout << a[i] << ";	";
	}
	cout << endl;
}

void Interchange_Sort ( double *&a, int n ) {
	for ( int i = 0; i <= n - 2; i++ ) {
		for ( int j = i + 1; j <= n - 1; j++ ) {
			if ( a[i] > a[j] )
				Swap ( a[i], a[j] );
		}
	}
}

int main () {
	double *a;
	int n;
	do {
		cout << "\nNhap so luong phan tu day so: ";
		cin >> n;
	} while ( n <= 0 );
	a = new double[n];

	cout << "\n\t\tNHAP DAY\n";
	NhapMang ( a, n );
	Interchange_Sort ( a, n );
	cout << "\nSAP XEP TANG DAN\n";
	XuatMang ( a, n );

	system ( "pause" );
	delete[]a;
	return 0;
}