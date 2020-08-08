#include<bits/stdc++.h>
using namespace std;

int ver, //số đỉnh
	edg, //số cạnh
	adj_mat[100][100], //Ma trận 2 chiều lưu ma trận kề
	arr_list[100][100], //Ma trận 2 chiều lưu danh sách cạnh
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
	cout << "--Ma tran ke:\n\n";
	for ( i = 1; i <= ver; i++ ) {
		for ( j = 1; j <= ver; j++ )
			cout << adj_mat[i][j] << " ";
		cout << endl;
	}
}

//Chuyển sang danh sách cạnh
void Trans_2_Arr_list () {
	int row = 1; // Số hàng trong ma trận lưu danh sách cạnh arr_list
	for ( i = 1; i <= ver; i++ ) {
		for ( j = 1; j <= ver; j++ ) {
			if ( adj_mat[i][j] == 1 ) {
				arr_list[row][1] = i;
				arr_list[row][2] = j;
				row++;// Xét sang hàng tiếp theo trong ma trận 2 chiều arr_list
			}
		}
	}
}

//In ra danh sách cạnh
void dis_Arr_list () {
	cout << "\n--Danh sach canh: \n" << "\nStarting Point" << "	|  " << "Ending Point\n\n";
	for ( i = 1; i <= edg; i++ ) {
		for ( j = 1; j <= 2; j++ ) {
			cout << "      " << arr_list[i][j] << "		  ";
		} cout << "\n\n";
	}
}

int main () {
	read_adj_mat ();
	dis_adj_mat ();
	Trans_2_Arr_list ();
	dis_Arr_list ();
	system ( "pause" );
}

/*
--Ma tran ke:

0 1 0 0 0 0
0 0 1 1 1 0
1 0 0 0 0 0
0 0 1 0 1 0
0 0 0 0 0 1
0 0 0 1 0 0

--Danh sach canh:

Starting Point  |  Ending Point

	  1                 2

	  2                 3

	  2                 4

	  2                 5

	  3                 1

	  4                 3

	  4                 5

	  5                 6

	  6                 4
*/