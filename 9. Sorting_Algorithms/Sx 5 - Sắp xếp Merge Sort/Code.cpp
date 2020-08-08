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

void merge ( double *a, int l, int m, int r ) {
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;

	/* Tạo các mảng tạm */
	double L[n1], R[n2];

	/* Copy dữ liệu sang các mảng tạm */
	for ( i = 0; i < n1; i++ ) L[i] = a[l + i];
	for ( j = 0; j < n2; j++ ) R[j] = a[m + 1 + j];

	/* Gộp hai mảng tạm vừa rồi vào mảng arr*/
	i = 0; // Khởi tạo chỉ số bắt đầu của mảng con đầu tiên
	j = 0; // Khởi tạo chỉ số bắt đầu của mảng con thứ hai
	k = l; // IKhởi tạo chỉ số bắt đầu của mảng lưu kết quả
	while ( i < n1 && j < n2 ) {
		if ( L[i] <= R[j] ) {
			a[k] = L[i];
			i++;
		} else {
			a[k] = R[j];
			j++;
		} k++;
	}

	/* Copy các phần tử còn lại của mảng L vào arr nếu có */
	while ( i < n1 ) {
		a[k] = L[i];
		i++;
		k++;
	}

	/* Copy các phần tử còn lại của mảng R vào arr nếu có */
	while ( j < n2 ) {
		a[k] = R[j];
		j++;
		k++;
	}
}

/* l là chỉ số trái và r là chỉ số phải của mảng cần được sắp xếp */
void MergeSort ( double *a, int l, int r ) {
	if ( l < r ) {
		// Tương tự (l+r)/2, nhưng cách này tránh tràn số khi l và r lớn
		int m = l + ( r - l ) / 2;

		// Gọi hàm đệ quy tiếp tục chia đôi từng nửa mảng
		MergeSort ( a, l, m );
		MergeSort ( a, m + 1, r );

		merge ( a, l, m, r );
	}
}

int main () {
	double *a;
	int n;
	cout << "Nhap do dai: "; cin >> n;
	a = new double[n];
	cout << "Nhap cac phan tu: "; Nhap ( a, n );
	cout << "Mang vua nhap: "; Xuat ( a, n );
	MergeSort ( a, 0, n - 1 );
	cout << "Mang da Sap xep: "; Xuat ( a, n );

	system ( "pause" );
}