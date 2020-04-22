#include<bits/stdc++.h>
using namespace std;
#define MAX 100 //kích thước lớn nhất của ma trận

int graph[MAX][MAX], // Ma trận 2 chiều lưu ma trận đọc được từ file
	result[MAX][MAX], // Ma trận 2 chiều lưu kết quả sau khi lũy thừa
	p, // bậc của lũy thừa
	n; // kích thước ma trận

//Hàm đọc file
void reader () {
	ifstream FileIn ( "graph.dat" ); // Khai báo biến, mở, đọc file
	FileIn >> n >> p; // nhận kích thước và bậc của lũy thừa
	for ( int i = 0; i < n; i++ ) //Nhận ma trân từ file vào graph
	for ( int j = 0; j < n; j++ )
		FileIn >> graph[i][j];
}

//Hàm lũy thừa ma trận
void multi_matrix () {
	int	temp[MAX][MAX]; //Ma trận 2 chiều tạm nhớ cấu hính ma trận result trước đó
	p--; //mũ 1 bằng chính nó nên ta giảm đi 1 đơn vị để tính từ mũ 2 (nếu n >= 2)

	for ( int i = 0; i < n; i++ ) {  //nhận ma trận khởi đầu từ graph vào result
		for ( int j = 0; j < n; j++ )
			result[i][j] = graph[i][j];
	}

	while ( p-- ) {
		for ( int i = 0; i < n; i++ ) { //nhận ma trận từ result vào temp
			for ( int j = 0; j < n; j++ )
				temp[i][j] = result[i][j];
		}

		for ( int i = 0; i < n; i++ ) { //Nhân ma trận
			for ( int j = 0; j < n; j++ ) {
				result[i][j] = 0;
				for ( int t = 0; t < n; t++ ) //xét từng cột một
					result[i][j] += temp[i][t] * graph[t][j]; //Hàng * cột
			}
		}
	}
}

//Hàm in ma trận
void display () {
	for ( int i = 0; i < n; i++ ) {
		for ( int j = 0; j < n; j++ ) {
			cout << result[i][j] << " ";
		} cout << "\n\n";
	}
}

int main () {
	reader ();
	multi_matrix ();
	display ();
	cout << "\n";
	system ( "pause" );
}