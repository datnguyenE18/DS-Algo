#include<bits/stdc++.h>
using namespace std;

/// Hàm chuyển từ mảng a thành mảng độc nhất của nó
vector<int> uniqueArray ( vector<int> arr ) {
	vector<int> b;

	/// sắp xếp mảng a theo thứ tự tăng dần
	sort ( arr.begin (), arr.end () );

	for ( int L = 0; L < ( int ) arr.size (); ++L ) {
		/// Xác định đoạn [L,R] sao cho các phần tử thuộc đoạn [L,R] có giá trị bằng nhau
		int R = L;
		while ( R < ( int ) arr.size () && arr[R] == arr[L] ) ++R;
		--R;

		/// Đưa phần tử đầu tiên của đoạn [L,R] vào mảng kết quả
		b.push_back ( arr[L] );

		L = R;
	}
	return b;
}


int main () {
	vector<int>arr = { 1, 2, 3, 2, 4, 1, 10 };
	for ( int i : uniqueArray ( arr ) ) cout << i << ", ";

	system ( "pause" );
}