#include<bits/stdc++.h>
using namespace std;

const int MAX = 1e4;
int root[MAX + 1]; //Lưu gốc các thùng

// Tìm gốc của một thùng:
int findRoot(int u) {
	if ( !root[u] ) return u; // Nếu nó không nối với thùng nào thì gốc của nó là chính nó
	return root[u] = findRoot(root[u]); // Tìm gốc của u
}

int main() {
	int x, //  Thùng X
		y, // Thùng Y
		z, // yêu cầu loại Z
		p; // Số yêu cầu
	ios::sync_with_stdio(0); // giảm thời gian chạy cin/cout 
	cin.tie(0); cout.tie(0); // ngăn sự đồng bộ giữa cin và cout: chỉ khi cout xuất ra hết thì cin mới nhập vào (và ngược lại)
	cin >> p;
	while ( p-- ) {
		cin >> x >> y >> z;
		int X = findRoot(x), // root của X
			Y = findRoot(y); // root của Y
		if ( z == 1 ) { // Yêu cầu mở van hai bình với nhau
			if ( X != Y ) // Nếu X và Y không chung gốc
				root[X] = Y; // Thì đưa gốc của gốc của X về là gốc của Y
		} else {
			if ( X == Y ) cout << 1 << endl;
			else cout << 0 << endl;
		}
	}
}