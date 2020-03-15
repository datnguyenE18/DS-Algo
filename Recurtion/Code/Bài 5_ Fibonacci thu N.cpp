/*Dãy Fibonacci:
Ta tìm được CTTQ là: f(n) = f(n - 1) + f(n - 2) => Ta áp vào đệ quy (Đã dạy trong bài hệ thức truy hồi ở TRR)
thêm điều kiện dừng nữa là OK*/

#include<bits/stdc++.h>
using namespace std;

int fibonacci ( int n ) {
	if ( n <= 2 ) return 1;
	return fibonacci ( n - 1 ) + fibonacci ( n - 2 );
}

int main () {
	int n;
	cout << "Ban muon tim so Fibonacci thu may? " << endl; cin >> n;
	cout << "So ban can tim: " << fibonacci ( n );
	system ( "pause" );
}