#include<bits/stdc++.h>
using namespace std;

int s1, //Số bit 1 trong xâu 
	n, //Độ dài xâu nhị phân 
	k, // Số bit 1 cần có
	num[17]; //Lưu xâu nhị phân

void display() {
	for ( int vt = 1; vt <= n; vt++ )
		cout << num[vt];
	cout << endl;
}

void qlNhiPhan(int vt) {
	for ( int gt = 0; gt <= 1; gt++ ) {
		num[vt] = gt;
		s1 += gt;
		if ( vt == n && s1 == k ) // Đủ n bit và có tổng bit 1 = K (cấu hình cuối)
			display();
		else if ( vt < n )
			qlNhiPhan(vt + 1);
		s1 -= gt;
	}
}

int main() {
	int t; cin >> t;
	while ( t-- ) {
		s1 = 0; //Đầu tiên chưa có bit 1 nào cả
		cin >> n >> k;
		qlNhiPhan(1);
	}
}
