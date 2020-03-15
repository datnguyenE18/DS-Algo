#include<bits/stdc++.h>
using namespace std;

void NhapMang ( int M[], int n ) {
	srand ( time ( NULL ) );
	for ( int i = 0; i < n; i++ )
		M[i] = rand () % 100;
}

void XuatMang ( int M[], int n ) {
	for ( int i = 0; i < n; i++ )
		cout << M[i] << "\t";
}

int LinearSearch ( int M[], int n, int x ) { // Tìm kiếm tuyến tính
	for ( int i = 0; i < n; i++ ) {
		if ( M[i] == x ) return i;
	} return 0;
}

int main () {
	int x;
	cout << "Nhap so luong phan tu mang: ";
	int n; cin >> n;
	int M[n];
	NhapMang ( M, n );
	cout << "Mang ngau nhien: \n";
	XuatMang ( M, n );
	cout << "\nNhap so can tim kiem: "; cin >> x;
	if ( LinearSearch ( M, n, x ) ) {
		cout << "Thay " << x << " dau tien tai vi tri thu " << LinearSearch ( M, n, x ) + 1 << endl;
	} else cout << "Khong tim thay " << x << " trong mang" << endl;

	system ( "pause" );
	return 0;
}