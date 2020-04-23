/*Tính tổ hợp chập k của n, C(n,k):
Ta tìm được CTTQ là: C(n,k) = C(n - 1 , k - 1) + C(n - 1 , k) => Ta áp vào đệ quy (Đã dạy trong bài hệ thức truy hồi ở TRR)
thêm điều kiện dừng nữa là OK*/

#include<bits/stdc++.h>
using namespace std;

int combine ( int n, int k ) {
	if ( k == 0 || k == n ) return 1;
	return( combine ( n - 1, k ) + combine ( n - 1, k - 1 ) );
}

int main () {
	int n, k;
	cout << "Tinh To Hop chap K cua N" << endl;
	cout << "Nhap K = "; cin >> k;
	cout << "Nhap N = "; cin >> n;
	cout << "nCk = " << combine ( n, k ) << endl;
	system ( "pause" );
}