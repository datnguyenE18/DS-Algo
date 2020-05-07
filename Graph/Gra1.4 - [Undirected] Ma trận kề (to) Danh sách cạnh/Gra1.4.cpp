#include<bits/stdc++.h>
using namespace std;

int ver, //số đỉnh
	row, // Số hàng trong ma trận lưu danh sách cạnh edg_list
	adj_mat[100][100], //Ma trận 2 chiều lưu ma trận kề
	edg_list[100][2], //Ma trận 2 chiều lưu danh sách cạnh
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

//chuyển sang danh sách cạnh
void Trans_2_edg_list () {
	row = 1; 
	for ( i = 1; i <= ver; i++ ) {
		for ( j = i + 1; j <= ver; j++ ) {
			if ( adj_mat[i][j] ) {
				edg_list[row][1] = i;
				edg_list[row][2] = j;
				row++;
			}
		}
	}
}

//In danh sách cạnh
void dis_edg_list () {
	cout << "\n--Danh sach canh: \n" << "\nStarting Point" << "	|  " << "Ending Point\n\n";
	for ( i = 1; i <= row - 1; i++ ) {
		for ( j = 1; j <= 2; j++ ) {
			cout << "      " << edg_list[i][j] << "		  ";
		} cout << "\n\n";
	}
}

int main () {
	read_adj_mat (); 		dis_adj_mat ();
	Trans_2_edg_list ();	dis_edg_list ();
	system ( "pause" );
}

