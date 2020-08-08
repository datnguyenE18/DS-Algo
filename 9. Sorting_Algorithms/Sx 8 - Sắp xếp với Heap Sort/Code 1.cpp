#include<bits/stdc++.h>
using namespace std;

// Hàm nhập xuất & đổi chỗ:
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

//Hàm hỗ trợ Heap Sort:

/*Hàm Heapify sẽ kiểm tra nút trái, nút phải và nút ngay tại vị trí offset để tìm ra nút có giá trị lớn nhất.
Trong trường hợp nút có giá trị lớn nhất không phải nút ở vị trí offset, hàm sẽ đổi giá trị 2 nút này và tiếp tục đệ quy Heapify từ vị trí
nút có giá trị lớn nhất để đi đến các nhánh tiếp theo để đảm bảo nút cha sẽ luôn có giá trị lớn hơn các nút con.*/
void Heapify ( double *a, int n, int offset ) {
	while ( offset <= n / 2 - 1 ) {
		int left = 2 * offset + 1;
		int right = 2 * offset + 2;
		int max = left;
		if ( right < n && a[right] > a[max] ) max = right;
		if ( a[offset] < a[max] ) swap ( a[offset], a[max] );
		offset = max;
	}
}

/*Hàm BuildHeap sẽ tạo heap từ dữ liệu đưa vào là mảng và kích thước mảng. Sử dụng vòng lặp tính từ vị trí giữa mảng,
BuildHeap sẽ lặp và sắp xếp các phần tử để tạo nên heap thỏa mãn các tính chất cần thiết bằng hàm Heapify.
*/
void BuildHeap ( double *a, int n ) {
	for ( int i = n / 2 - 1; i >= 0; i-- ) Heapify ( a, n, i );
}

//Hàm Sắp Xếp Heap:
void HeapSort ( double *a, int n ) {
	BuildHeap ( a, n );
	for ( int i = n - 1; i >= 0; i-- ) {
		swap ( a[0], a[i] );
		Heapify ( a, i, 0 );
	}
}

int main () {
	double *a;
	int n;

	cout << "Nhap n: "; cin >> n;
	a = new double[n];
	cout << "Nhap cac phan tu: "; Nhap ( a, n );
	cout << "Cac phan tu da nhap: "; Xuat ( a, n );
	HeapSort ( a, n );
	cout << "Da sap xep: "; Xuat ( a, n );

	system ( "pause" );
}
