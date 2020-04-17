#include <bits/stdc++.h>
using namespace std;
#define MAX 11111

int graph[MAX][MAX], // Ma trận 2 chiều lưu ma trận đọc được
size, //kích thước ma trận
rows, cols; //hàng và cột
string line;

void reader ( string file ) {
	ifstream FileIn ( file ); //Khai báo biến, mở và đọc file

	for ( rows = 0; getline ( FileIn, line ); rows++ ) {
		string element = "";
		cols = 0; // quét từng cột một bắt đầu từ cột 0
		for ( int t = 0; t < line.length (); t++ ) {
			if ( line[t] != ' ' ) // Nếu ký tự hiện tại khác dấu cách => nối vào biến element
				element += line[t];

			if ( line[t] == ' ' || t == line.length () - 1 ) { // Nếu ký tự hiện tại là dấu cách, hoặc là ký tự cuối của hàng
				graph[rows][cols] = atoi ( element.c_str () ); // Thực hiện chuyển string thành số int, hàm atoi chỉ nhận vào biến kiểu char*, nên cần dùng .c_str() để chuyển từ string về char*
				cols++; // cột tiếp theo
				element = ""; // Đặt lại giá trị element
			}
		}
		size = cols; //Lấy luôn số phần tử của hàng đầu tiên làm kích thước ma trận để thực hiện hàm Display
	}
}


void Display () {
	for ( int i = 0; i < size; ++i ) {
		for ( int j = 0; j < size; j++ )
			cout << graph[i][j] << " ";
		cout << "\n";
	}
}


int main () {
	reader ( "input.dat" );
	Display ();
	system ( "pause" );
}
