#include<bits/stdc++.h>
using namespace std;
#define MAX 100

int n, // n*n : Số ô (Số hàng / số cột)
	dem, // đếm số cách đặt quân hậu trên bàn cờ
	res[MAX], //Ghi kết quả
	col[MAX], //Kiểm tra cột
	right_dia[2 * MAX], //Kiểm tra đường chéo phải
	left_dia[2 * MAX]; //Kiểm tra đường chéo trái

//Khởi tạo các giá trị ban đầu khi chưa đặt quân hậu nào
void Init () {
	dem = 0; //Ban đầu có 0 cách xếp quân hậu
	for ( int j = 1; j <= n; j++ )
		col[j] = 1; // các cột đều cho phép đặt quân hậu đầu tiên

	//Ban đầu các đường chéo trống và đều cho phép đặt quân hậu đầu tiên
	for ( int k = 1; k <= 2 * n - 1; k++ ) {
		right_dia[k] = 1;
		left_dia[k] = 1;
	}
}

void display () {
	cout << "Case " << dem + 1 << "	:	[ ";
	for ( int i = 1; i <= n; i++ ) //Xét từng hàng
		cout << res[i] << " ";
	cout << "] \n";
}

void Try ( int i ) { //kiểm tra hàng thứ i (1 <= i <= n)
	for ( int j = 1; j <= n; j++ ) { //Kiểm tra từng cột ở hàng i
		if ( right_dia[i - j + n] && left_dia[i + j - 1] && col[j] ) {
			res[i] = j; //Quân hậu đặt ở hàng i sẽ đặt ở cột j
			col[j] = 0; //Không đặt quân hậu khác ở cột j
			right_dia[i - j + n] = 0; //Không đặt quân hậu khác vào đường chéo i - j + n
			left_dia[i + j - 1] = 0; //Không đặt quân hậu khác vào đường chéo i + j - 1
			if ( i == n ) {
				display (); //Nếu đã đặt quân hậu ở hàng cuối cùng thì in ra kết quả
				dem++;
			} else Try ( i + 1 ); //Đặt quân hậu ở hàng tiếp theo
			// Trả về giá trị quay lui để dùng cho trường hợp tiếp theo:
			col[j] = 1;
			right_dia[i - j + n] = 1;
			left_dia[i + j - 1] = 1;
		}
	}
}


int main () {
	int t; cin >> t; // Số bộ test
	while ( t-- ) {
		cin >> n;
		Init ();
		Try ( 1 );
		if ( dem == 0 ) cout << "-1\n";
		else cout << "\n";
	}
	return 0;
}

/*
2
4
Case 1  :       [ 2 4 1 3 ]
Case 2  :       [ 3 1 4 2 ]

5
Case 1  :       [ 1 3 5 2 4 ]
Case 2  :       [ 1 4 2 5 3 ]
Case 3  :       [ 2 4 1 3 5 ]
Case 4  :       [ 2 5 3 1 4 ]
Case 5  :       [ 3 1 4 2 5 ]
Case 6  :       [ 3 5 2 4 1 ]
Case 7  :       [ 4 1 3 5 2 ]
Case 8  :       [ 4 2 5 3 1 ]
Case 9  :       [ 5 2 4 1 3 ]
Case 10 :       [ 5 3 1 4 2 ]
*/