#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void Nhap ( double *&arr, int n ) {
	for ( int i = 0; i < n; i++ ) cin >> arr[i];
}

void Xuat ( double *arr, int n ) {
	for ( int i = 0; i < n; i++ ) cout << arr[i] << " ";
	cout << endl;
}

bool comp ( double i, double j ) { return ( i > j ); }

int main () {
	double *arr;
	int n;
	cout << "Nhap n: "; cin >> n;
	arr = new double[n];
	cout << "Nhap mang: "; Nhap ( arr, n );
	cout << "Mang da nhap: "; Xuat ( arr, n );

	//SẮP XẾP TĂNG DẦN:
	sort ( arr, arr + n ); // sắp xếp arr từ phần tử 0 đến phần tử n-1 
	cout << "Tang dan:"; Xuat ( arr, n );

	//SẮP XẾP GIẢM DẦN:
	sort ( arr, arr + n, comp );
	cout << "Giam dan: "; Xuat ( arr, n );

	system ( "pause" );
}