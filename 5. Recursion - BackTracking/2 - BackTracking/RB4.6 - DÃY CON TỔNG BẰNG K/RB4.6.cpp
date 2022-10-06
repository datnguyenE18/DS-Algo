#include<bits/stdc++.h>
using namespace std;
#define MAX 1001

int n, k, a[MAX], mark[MAX];
bool exist; //Kiểm tra xem có tồn tại bộ số nào không

void init() {
	exist = false;
	cin >> n >> k;
	for ( int i = 0; i < n; i++ )
		cin >> a[i];
	sort(a, a + n);
}

void display() {
	vector<int> ans;
	ans.clear();

	for ( int i = 0; i < n; i++ ) {
		if ( mark[i] == 1 )
			ans.push_back(a[i]);
	}

	cout << "[";
	for ( int j = 0; j < ans.size() - 1; j++ ) {
		cout << ans[j] << " ";
	}
	cout << ans[ans.size() - 1] << "] ";
}

void check() {
	int sum = 0;
	for ( int i = 0; i < n; i++ ) {
		if ( mark[i] == 1 ) //Nếu đánh dấu tại vị trí thứ i (trong a[]) là 1 
			sum += a[i]; //thì tính nó vào tổng
	}

	if ( sum == k ) {
		exist = true;
		display();
	}
}

// Quay lui nhị phân, bit 1 thì tính vào tổng , bit 0 thì bỏ qua
void qlNhiPhan(int i) {
	for ( int bit = 1; bit >= 0; bit-- ) {
		mark[i] = bit; // Đánh dấu Số tại vị trí thứ i trong mảng a[],
		if ( i == n - 1 ) check(); // Nếu đã chọn đến cuối rồi thì chuyển lên hàm check xem tổng có = K hay không
		else qlNhiPhan(i + 1); //Nếu chưa quét đến cuối thì xét tiếp
	}
}

void solve() {
	qlNhiPhan(0);
	if ( !exist )
		cout << "-1";
	cout << endl;
}

int main() {
	int t; cin >> t;
	while ( t-- ) {
		init();
		solve();
	}
}