#include<stdlib.h>
#include<iostream>
using namespace std;

//HÀM NHẬP - XUẤT:
void Nhap ( double *&arr, int n ) {
	for ( int i = 0; i < n; i++ ) cin >> arr[i];
}

void Xuat ( double *arr, int n ) {
	for ( int i = 0; i < n; i++ ) cout << arr[i] << " ";
	cout << endl;
}

//HÀM SO SÁNH TĂNG:
/*int cmpUp ( const void *a, const void *b ) {
	double aa = *( double* ) a;
	double bb = *( double* ) b;

	if ( aa > bb ) return 1;
	else if ( aa < bb ) return -1;
	else return 0;
}*/
//Viết gọn lại:
int cmpUp ( const void *a, const void *b ) { //lúc nào cũng phải là kiểu trả về int
	return ( *( double* ) a - *( double* ) b );
}

//HÀM SO SÁNH GIẢM:
/*int cmpDo ( const void *a, const void *b ) {
double aa = *( double* ) a;
double bb = *( double* ) b;

if ( aa > bb ) return -1;
else if ( aa < bb ) return 1;
else return 0;
}*/
//Viết gọn lại:
int cmpDo ( const void *a, const void *b ) { //lúc nào cũng phải là kiểu trả về int
	return ( *( double* ) b - *( double* ) a );
}

//HÀM CHÍNH:
int main () {
	double *arr;
	int n;

	cout << "Nhap n: "; cin >> n;
	arr = new double[n];
	cout << "Nhap mang: "; Nhap ( arr, n );
	cout << "Mang da nhap: "; Xuat ( arr, n );

	//SẮP XẾP TĂNG DẦN THEO QUICK-SORT:
	qsort ( arr, n, sizeof( double ), cmpUp );
	cout << "Tang dan:"; Xuat ( arr, n );

	//SẮP XẾP GIẢM DẦN THEO QUICK-SORT:
	qsort ( arr, n, sizeof( double ), cmpDo );
	cout << "Giam dan:"; Xuat ( arr, n );

	system ( "pause" );
}