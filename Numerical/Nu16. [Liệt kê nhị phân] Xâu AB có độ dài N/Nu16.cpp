#include<iostream>
using namespace std;

int n;
char a[11];
bool check; // tạo 1 biến kiểu bool để kiểm tra xem đã đến cấu hình cuối chưa

void display () {  // hiển thị cấu hình ra màn hình
	for ( int i = 1; i <= n; i++ ) cout << a[i];
	cout << " ";
}

void nextString () {
	int i = n;
	while ( a[i] == 'B' && i > 0 ) 	i--;
	if ( i == 0 ) check = true; // nếu i=0 tức là đã đến cấu hình cuối, gán biến check = true
	else {
		a[i] = 'B';    // còn không thì gán a[i]=1
		for ( int j = i + 1; j <= n; j++ ) a[j] = 'A';   // gán tất cả phần tử phía sau a[i] =0
	}
}

int main () {
	int t; cin >> t;

	while ( t-- ) {
		check = false;
		cin >> n;
		for ( int i = 1; i <= n; i++ ) a[i] = 'A';    // cấu hình đầu tiên gồm toàn số 0

		while ( !check ) {
			display ();       // hiển thị cấu hình
			nextString ();      // sinh cấu hình tiếp theo
		} cout << "\n";
	} system ( "pause" );
}