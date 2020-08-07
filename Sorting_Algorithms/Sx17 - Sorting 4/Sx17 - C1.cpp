#include<bits/stdc++.h>
using namespace std;

const int maxN = 1e5 + 1;
int a[maxN], b[maxN], n, m,
	da[maxN], db[maxN];

void input() {
	cin >> n >> m;
	for ( int i = 0; i < n; i++ )
		cin >> a[i];

	for ( int i = 0; i < m; i++ )
		cin >> b[i];

	for ( int i = 0; i <= 1e5; i++ )
		da[i] = db[i] = 0;
}

void solve() {
	// Dùng 2 mảng đánh dấu:
	for ( int i = 0; i < n; i++ ) da[a[i]] = 1;
	for ( int i = 0; i < m; i++ ) db[b[i]] = 1;

	// Phần tử nào xuất hiện ở một trong hai thì cho vào mảng hop
	for ( int i = 0; i <= 1e5; i++ )
		if ( da[i] == 1 || db[i] == 1 )
			cout << i << ' ';
	cout << endl;

	// Phần tử nào xuất hiện trong cả hai mảng thì cho vào mảng giao nhau
	for ( int i = 0; i <= 1e5; i++ )
		if ( da[i] == 1 && db[i] == 1 )
			cout << i << ' ';
	cout << endl;

	// Vì ta lấy các phần tử trong 2 mảng ban đầu để làm địa chỉ, nên vốn nó đã sắp xếp tăng dần từ bé đến lớn rồi nên ta không phải sort kết quả nữa
}

int main() {
	int t; cin >> t;
	while ( t-- ) {
		input();
		solve();
	}
}