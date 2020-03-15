/*S(n) = n!
Ta tìm được CTTQ là: S(n) = n. S(n-1)! => Ta áp vào đệ quy (Rất liên quan đến truy hồi trong TRR)
thêm điều kiện dừng nữa là OK*/

#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll factorial ( int n ) {
	if ( n == 0 || n == 1 ) return 1;
	else return n * factorial ( n - 1 );
}

int main ( ) {
	int n;
	cout << "Nhap n= "; cin >> n;
	cout << "n!= " << factorial ( n );
	system ( "pause" );
}