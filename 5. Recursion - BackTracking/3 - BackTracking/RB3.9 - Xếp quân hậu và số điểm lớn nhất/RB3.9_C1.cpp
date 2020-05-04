#include<bits/stdc++.h>
using namespace std;

int ans = 0, //Lưu kết quả cuối cùng
	A[9][9], //Lưu giá từng ô bàn cờ
	col[8],
	right_dia[16],
	left_dia[16],
	save[1000]; //Lưu địa chỉ cột được chọn

//Nhập bàn cờ:
void imp_board () {
	for ( int row = 1; row <= 8; row++ ) {
		for ( int col = 1; col <= 8; col++ )
			cin >> A[row][col];
	}
}


//Khởi tạo các giá trị ban đầu:
void init () {
	for ( int i = 1; i <= 16; i++ ) {
		col[i] = 1;
		right_dia[i] = 1;
		left_dia[i] = 1;
	}
}

int sum () {
	int sum = 0;
	for ( int i = 1; i <= 8; i++ )
		sum += A[i][save[i]];
	return sum;
}

void Try ( int i ) {
	for ( int j = 1; j <= 8; j++ ) { //Duyệt từng cột một
		if ( col[j] && right_dia[i - j + 8] && left_dia[i + j - 1] ) {
			save[i] = j;
			col[j] = 0;
			right_dia[i - j + 8] = 0;
			left_dia[i + j - 1] = 0;
			if ( i == 8 ) {
				ans = max ( ans, sum () );
			} else Try ( i + 1 );
			col[j] = 1;
			right_dia[i - j + 8] = 1;
			left_dia[i + j - 1] = 1;
		}
	}
}

int main () {
	int t; cin >> t;
	while ( t-- ) {
		ans = 0;
		imp_board ();
		init ();
		Try ( 1 );
		cout << ans << "\n";
	}
}

/*
1
1 2 3 4 5 6 7 8
9 10 11 12 13 14 15 16
17 18 19 20 21 22 23 24
25 26 27 28 29 30 31 32
33 34 35 36 37 38 39 40
41 42 43 44 45 46 47 48
48 50 51 52 53 54 55 56
57 58 59 60 61 62 63 64
260
*/