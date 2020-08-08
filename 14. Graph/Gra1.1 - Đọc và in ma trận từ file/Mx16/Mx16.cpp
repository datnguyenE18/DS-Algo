#include<bits/stdc++.h>
using namespace std;
#define MAX 100 //Kích thước tối đa của ma trận

int n, // Kích thước ma trận 
graph[MAX][MAX]; // Ma trận 2 chiều sẽ lưu ma trận đọc được

void display ( ) {
	ifstream FileIn ( "input.dat" ); //Khai báo biến, mở và đọc file 
	FileIn >> n; // nhận kích thước ma trận

	// Đọc ma trận
	for ( int i = 0; i < n; i++ )
		for ( int j = 0; j < n; j++ )
			FileIn >> graph[i][j];

	//In ma trận
	for ( int i = 0; i < n; i++ ) {
		for ( int j = 0; j < n; j++ )
			cout << graph[i][j] << " ";
		cout << "\n";
	}
	FileIn.close ( ); // đóng file
}

int main ( ) {
	display ( );
	system ( "pause" );
}
