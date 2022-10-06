/*S(n) = 1^2 + 2^2 +...+ (n-1)^2 + n^2
S(1) = 1
Ta tìm được CTTQ là: S(n) = n^2 + S(n - 1) => ta áp vào đệ quy (Rất liên quan đến truy hồi trong TRR)
thêm điều kiện dừng nữa là OK*/

#include<bits/stdc++.h>
using namespace std;

int total ( int n ) {
	if ( n == 1 ) return 1;
	return pow ( n, 2 ) + total ( n - 1 );
}

int main () {
	int n;
	cout << "Nhap n = "; cin >> n;
	cout << "KQ = " << total ( n ) << endl;

	system ( "pause" );
}