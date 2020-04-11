#include<bits/stdc++.h>
using namespace std;

int t, n, a[16];
bool check;

void init () { // Cấu hình đầu tiên
	for ( int i = 1; i <= n; i++ )
		a[i] = i;
}

void display ( int n, int a[] ) { // In ra cấu hình hiện tại
	for ( int i = 1; i <= n; i++ ) cout << a[i];
	cout << " ";
}

void next_permu ( int n, int a[] ) {
	int i = n - 1; //Duyệt từ vị trí n - 1
	while ( i > 0 && a[i] > a[i + 1] ) i--; // tìm vị trí để x[i] < x[i + 1]

	if ( i > 0 ) { //Nếu tìm thấy i sao cho: x[i] < x[i + 1]
		int j = n; //Duyệt từ cuối lên
		while ( a[i] > a[j] ) j--; //Tìm vị trí j để x[i] < x[j]
		swap ( a[i], a[j] ); // đổi giá trị x[i] cho x[k]
		int k = i + 1, h = n;
		while ( k <= h ) { // Lật ngược đoạn x[i] + 1, ... , x[n]
			swap ( a[k], a[h] );
			k++;
			h--;
		}
	} else check = false; //ghi nhận đã đến cuối cùng
}

int main () {
	cin >> t;

	while ( t-- ) {
		check = true;
		cin >> n;
		init ();
		while ( check ) {
			display ( n, a );
			next_permu ( n, a );
		} cout << "\n";
	} system ( "pause" );
}
