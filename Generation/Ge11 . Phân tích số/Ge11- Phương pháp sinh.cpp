#include<bits/stdc++.h>
using namespace std;

int t, n, k, a[11111];
bool stop;

void Init () {
	k = 1;
	a[k] = n;
}

void display () {
	cout << "(";
	for ( int i = 1; i < k; i++ )
		cout << a[i] << " ";
	cout << a[k] << ") ";
}

void gen () {
	int i = k; //duyệt từ cuối lên
	while ( i > 0 && a[i] == 1 ) i--; // Nếu chưa phải cấu hình cuối cùng hoặc bằng 1 thì tiếp tục duyệt lên
	if ( i <= 0 ) stop = true; // Nếu đã là cấu hình cuối cùng thì dừng
	else {
		a[i]--; //giảm a[i] đi một đơn vị
		int d = k - i + 1;
		k = i;
		for ( int j = i + 1; j <= i + d / a[i]; j++ )
			a[j] = a[i];
		k += d / a[i];
		if ( d % a[i] ) a[++k] = d % a[i];
	}
}

int main () {
	cin >> t;
	while ( t-- ) {
		cin >> n;
		Init ();
		stop = false;
		while ( !stop ) {
			display ();
			gen ();
		} cout << "\n";
	} system ( "pause" );
}