#include<bits/stdc++.h>
using namespace std;

int ver, //số đỉnh
	edg, //số cạnh
	adj_mat[100][100], //Ma trận 2 chiều lưu ma trận kề
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
	read_adj_mat ();
	dis_adj_mat ();
	Trans_2_Adj_list ();
	dis_Adj_list ();
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

--Danh sach ke:

ke[1]= { 2 }

ke[2]= { 3, 4, 5 }

ke[3]= { 1 }

ke[4]= { 3, 5 }

ke[5]= { 6 }

ke[6]= { 4 }
*/