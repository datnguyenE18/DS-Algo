#include<bits/stdc++.h>
using namespace std;

void NhapMang ( int M[], int n ) {
	cout << "Nhap mang M theo thu tu: \n";
	for ( int i = 0; i < n; i++ ) {
		cin >> M[i];
	}
}

void XuatMang ( int M[], int n ) {
	for ( int i = 0; i < n; i++ )
		cout << M[i] << "\t";
}

int BinarySearch ( int M[], int n, int x ) { // Tìm kiếm nhị phân
	int left = 0, right = n - 1, mid;
	do {
		mid = ( left + right ) / 2;
		if ( M[mid] == x ) return mid;
		else if ( x < mid ) right = mid - 1;
		else return left = mid + 1;
	} while ( left <= right );
	return -1;
}

int main () {
	int x;
	cout << "Nhap so luong phan tu mang: ";
	int n; cin >> n;
	int M[n];
	NhapMang ( M, n );
	cout << "Mang sau khi nhap: \n";
	XuatMang ( M, n );
	cout << "\nNhap so can tim kiem: "; cin >> x;
	if ( BinarySearch ( M, n, x ) ) {
		cout << "Thay " << x << " dau tien tai vi tri thu " << BinarySearch ( M, n, x ) + 1 << endl;
	} else cout << "Khong tim thay " << x << " trong mang" << endl;

	system ( "pause" );
	return 0;
}
