/*
**Next_subset
*/

#include<bits/stdc++.h>
using namespace std;

int t, n, k;
int x[111111];

void Input () { // nhập cấu hình ban đầu
	for ( int i = 1; i <= k; i++ ) cin >> x[i];
}

void next_Subset () {
	int i = k; // duyệt từ cuối lên của tập con hiện tại
	while ( i > 0 && x[i] == n - k + i ) i--; // tìm i sao cho x[i] khác n - k + i

	if ( i > 0 ) { // nếu tìm thấy i
		x[i] = x[i] + 1; // tăng x[i] lên một đơn vị
		for ( int j = i + 1; j <= k; j++ )  // từ đó về sau mỗi phần tử tăng thêm (j - i) đơn vị
			x[j] = x[i] + j - i;
	} else { // nếu không tìm thấy i => cấu hính cuối
		for ( i = 1; i <= k; i++ ) x[i] = i; // thì trả về cấu hình đầu tiên
	}
}

void Output () { //in ra cấu hình hiện tại
	for ( int i = 1; i <= k; i++ ) cout << x[i] << " ";
	cout << endl;
}

int main () {
	cin >> t;
	while ( t-- ) {
		cin >> n >> k;
		Input ();
		next_Subset ();
		Output ();
	} system ( "pause" );
}
