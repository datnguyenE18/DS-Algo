#include<bits/stdc++.h>
#define MAX 1001
using namespace std;

int n, k, num[MAX];

// Khởi tạo:
void init() {
	cin >> n >> k;
	for ( int i = 1; i <= k; i++ )
		cin >> num[i];
}

//Hàm sinh tập con kế tiếp:
void next_Subset() {
	for ( int i = k; i > 0; i-- ) { //Duyệt từ cuối lên
		if ( num[i] == n - k + i ) continue; // tìm i sao cho num[i] khác n - k + i
		else { //Nếu tìm thấy i
			num[i] ++; //thì tăng giá trị num[i] lên 1 đơn vị
			for ( int j = i + 1; j <= k; j++ ) //Từ vị trí tiếp đó về cuối
				num[j] = num[i] + j - i; //mỗi vị trí tăng giá trị lên (j - i) đơn vị
			return;
		}
	}
	for ( int i = 1; i <= k; i++ )  // Nếu không tìm thấy i => cấu hình cuối
		num[i] = i; // thì trả về cấu hình đầu tiên
}

// In ra cấu hình hiện tại:
void display() {
	for ( int i = 1; i <= k; i++ )
		cout << num[i] << " ";
	cout << endl;
}

int main() {
	int t; cin >> t;
	while ( t-- ) {
		init();
		next_Subset();
		display();
	}
}