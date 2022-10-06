#include<bits/stdc++.h>
using namespace std;

vector<int> x ( 11 ); //Lưu vị trí
vector<vector<int> > v; //Ma trận hai chiều lưu bộ các kết quả theo từ hàng
int a[11][11], // lưu ma trận ban đầu
	n, k;
bool check[11]; // Kiểm tra xem giá trị cột này ở hàng đó đã xét qua chưa

bool checkSum () {
	int s = 0;
	for ( int i = 1; i <= n; i++ )
		s += a[i][x[i]]; //các hàng i cột x[i]
	return ( s == k );
}

void qlHoanVi ( int i ) {
	for ( int j = 1; j <= n; j++ ) {
		if ( !check[j] ) { //Nếu cột này ở hàng đó chưa xét qua thì 
			x[i] = j; //Lưu vị trí này vào x[i]
			check[j] = true; //rồi lưu nó là đã xét
			if ( i == n ) { // Nếu đã đến hàng cuối cùng rồi thì chuyển các giá trị trong ma trận v vừa lưu lên hàm checkSum 
				if ( checkSum () )
					v.push_back ( x );
			} else qlHoanVi ( i + 1 ); //Nếu chưa đến hàng cuối cùng thì xét hàng tiếp theo
			check[j] = false; //sau khi xét xong thì đánh dấu lại để phục vụ cho lần xét kế tiếp
		}
	}
}

int main () {
	cin >> n >> k;
	for ( int i = 1; i <= n; i++ ) {
		for ( int j = 1; j <= n; j++ )
			cin >> a[i][j];
	}

	qlHoanVi ( 1 );
	cout << v.size () << endl;
	for ( int i = 0; i < v.size (); i++ ) {
		for ( int j = 1; j <= n; j++ )
			cout << v[i][j] << " ";
		cout << endl;
	} system ( "pause" );
}
