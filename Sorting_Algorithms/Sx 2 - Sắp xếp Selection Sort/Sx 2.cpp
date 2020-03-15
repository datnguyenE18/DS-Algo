#include<bits/stdc++.h>
using namespace std;

void swap ( double &a, double &b ) {
	double temp = a;
	a = b;
	b = temp;
}

void selection_sort ( double *&arr, int n ) {
	int min;
	for ( int i = 0; i < n - 1; i++ ) {
		min = i;
		for ( int j = i + 1; j < n; j++ ) {
			if ( arr[j] <= arr[min] ) min = j;
		} swap ( arr[min], arr[i] );
	}
}

void Nhap_mang ( double *&arr, int n ) {
	for ( int i = 0; i < n; i++ ) {
		cout << "Nhap arr[" << i << "] = ";
		cin >> arr[i];
	}
}

void Xuat_mang ( double *arr, int n ) {
	for ( int i = 0; i < n; i++ ) cout << arr[i] << ", ";
}

int main () {
	double *a;
	int n;
	cout << "Nhap so phan tu mang: ";
	cin >> n; cout << endl;
	a = new double[n];
	Nhap_mang ( a, n ); cout << endl;
	cout << "Mang da nhap: "; Xuat_mang ( a, n ); cout << endl;
	selection_sort ( a, n );
	cout << "\nMang sau khi Sap xep: "; Xuat_mang ( a, n ); cout << endl;

	system ( "pause" );
}