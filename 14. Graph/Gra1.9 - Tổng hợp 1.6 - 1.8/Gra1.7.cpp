#include<bits/stdc++.h>
using namespace std;

int ver, //số đỉnh
	edg, //số cạnh
	adj_mat[100][100], //Ma trận 2 chiều lưu ma trận kề
	inc_mat[100][100], //Ma trận 2 chiều lưu ma trận liên thuộc
	arr_list[100][100], //Ma trận 2 chiều lưu danh sách cạnh
	i, j;
vector< vector<int> > adj_list; //Ma trận 2 chiều lưu danh sách kề

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
	cout << "\n--Ma tran lien thuoc:\n\n";
	for ( i = 1; i <= ver; i++ ) {
		for ( j = 1; j <= edg; j++ ) {
			if ( inc_mat[i][j] == -1 ) cout << inc_mat[i][j] << " ";
			else cout << " " << inc_mat[i][j] << " ";
		} cout << "\n";
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

//Chuyển sang danh sách kề
void Trans_2_Adj_list () {
	for ( i = 1; i <= ver; i++ ) {
		vector<int> v;
		for ( j = 1; j <= ver; j++ ) {
			if ( adj_mat[i][j] == 1 )
				v.push_back ( j );
		}
		adj_list.push_back ( v );
	}
}

//In ra danh sách kề
void dis_Adj_list () {
	cout << "\n--Danh sach ke: \n\n";
	for ( i = 0; i < adj_list.size (); i++ ) {
		cout << "Adj[" << i + 1 << "]= { ";
		for ( j = 0; j < adj_list[i].size () - 1; j++ )
			cout << adj_list[i][j] << ", ";
		cout << adj_list[i][adj_list[i].size () - 1] << " }\n\n";
	}
}

int main () {
	read_adj_mat (); 		dis_adj_mat ();
	Trans_2_Inc_mat ();		dis_Inc_mat ();
	Trans_2_Arr_list ();	dis_Arr_list ();
	Trans_2_Adj_list ();	dis_Adj_list ();
	system ( "pause" );
}

