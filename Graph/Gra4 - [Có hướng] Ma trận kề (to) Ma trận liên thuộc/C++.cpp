#include<bits/stdc++.h>
using namespace std;

int ver, //số đỉnh
	edg = 0, //số cạnh
	adj_mat[100][100], //Ma trận 2 chiều lưu ma trận kề
	inc_mat[100][100], //Ma trận 2 chiều lưu ma trận liên thuộc
	i, j;

// Hàm đọc ma trận kề và các thành phần từ file
void read_adj_mat () {
	ifstream FileIn;
	FileIn.open ( "graph.dat", ios_base::in );
	FileIn >> ver; //Nhận số đỉnh

	//Nhận ma trận kề:
	for ( i = 1; i <= ver; i++ ) {
		for ( j = 1; j <= ver; j++ )
			FileIn >> adj_mat[i][j];
	}
	FileIn.close ();

	//Lấy ra số cạnh của ma trận:
	for ( i = 1; i <= ver; i++ ) {
		for ( j = 1; j <= ver; j++ ) {
			if ( adj_mat[i][j] == 1 )
				edg++;
		}
	}
}

//In ra ma trận kề vừa đọc
void dis_adj_mat () {
	cout << "Ma tran ke:\n\n";
	for ( i = 1; i <= ver; i++ ) {
		for ( j = 1; j <= ver; j++ )
			cout << adj_mat[i][j] << " ";
		cout << endl;
	}
}

//Chuyển sang ma trận liên thuộc
void Trans_2_Inc_mat () {
	int brd = 1; //Bridge
	for ( i = 1; i <= ver; i++ ) {
		for ( j = 1; j <= ver; j++ ) {
			if ( adj_mat[i][j] == 1 ) { // tức là i nối với j qua bridge
				inc_mat[i][brd] = 1;
				inc_mat[j][brd] = -1;
				brd++;
			}
		}
	}
}

//In ra ma trận liên thuộc
void dis_Inc_mat () {
	cout << "\nMa tran lien thuoc:\n\n";
	for ( i = 1; i <= ver; i++ ) {
		for ( j = 1; j <= edg; j++ ) {
			if ( inc_mat[i][j] == -1 ) cout << inc_mat[i][j] << " ";
			else cout << " " << inc_mat[i][j] << " ";
		} cout << "\n";
	}
}

int main () {
	read_adj_mat ();
	dis_adj_mat ();
	Trans_2_Inc_mat ();
	dis_Inc_mat ();
	system ( "pause" );
}

/*
Ma tran ke:

0 1 0 0 0 0
0 0 1 1 1 0
1 0 0 0 0 0
0 0 1 0 1 0
0 0 0 0 0 1
0 0 0 1 0 0

Ma tran lien thuoc:

 1  0  0  0 -1  0  0  0  0
-1  1  1  1  0  0  0  0  0
 0 -1  0  0  1 -1  0  0  0
 0  0 -1  0  0  1  1  0 -1
 0  0  0 -1  0  0 -1  1  0
 0  0  0  0  0  0  0 -1  1
 */