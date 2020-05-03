#include<bits/stdc++.h>
using namespace std;

int ver, //số đỉnh
adj_mat[100][100], // Mảng 2 chiều lưu ma trận kề
i, j, node;
bool visited[100];//Lưu tình trạng duyệt của node

double density; // density = ratio between #edges / N^2 - tỉ lệ cạnh


//Hàm sinh số ngẫu nhiên trong khoảng [0 , 1]:
double prob () {
	return ( double ) rand () / RAND_MAX;
}

//Hàm tạo ma trận kề ngẫu nhiên từ ver và density cho trước
void rand_graph () {
	int edge_count = 0;

	//Ban đầu tạo ma trận ver đỉnh chỉ chứa 0 (Tức các đỉnh rời rạc không nối với nhau):
	for ( i = 0; i < ver; i++ ) {
		for ( j = 0; j < ver; j++ )
			adj_mat[i][j] = 0;
	}

	//Tìm ngẫu nhiên vị trí trong ma trận (tìm các đỉnh để nối với nhau):
	for ( i = 0; i < ver; i++ ) {
		for ( j = i + 1; j < ver; j++ ) {
			if ( prob () < density ) { //density càng lớn thì càng nhiều đỉnh được nối
				adj_mat[i][j] = 1;
				adj_mat[j][i] = 1;
				edge_count++;
			}
		}
	}
	cout << "\n Created random graph with density " << density << " vs actual density is:  " << ( double ) 2 * edge_count / ( ver*ver ) << ":\n\n";
}

//Đọc ma trận kề từ file
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
	cout << "Read adjacency matrix from a file: \n\n";
}

//In ra ma trận kề vừa Đọc / Tạo
void dis_adj_mat () {
	for ( i = 1; i <= ver; i++ ) {
		for ( j = 1; j <= ver; j++ )
			cout << adj_mat[i][j] << " ";
		cout << endl;
	}
}

//DFS sử dụng ngăn xếp (khử đệ quy):
void DFS_stack ( int node ) {
	stack <int> stack0;
	stack0.push ( node );
	visited[node] = true;
	cout << node << " ";
	while ( !stack0.empty () ) {
		int s = stack0.top ();
		stack0.pop ();
		for ( int i = 1; i <= ver; i++ ) {
			if ( visited[i] == false && adj_mat[s][i] == 1 ) {
				cout << i << " ";
				visited[i] = true;
				stack0.push ( s );
				stack0.push ( i );
				break;
			}
		}
	}
}

int main () {
	//Menu:
	cout << "Options:\n\n";
	cout << "0 - Read From File \n\n1 - Random Graph\n\nYour option: ";
	int option; cin >> option;
	cout << "------------------------------------------------------------\n";

	if ( option == 1 ) {
		cout << "Vertex = "; cin >> ver;
		cout << "Density = "; cin >> density;
		rand_graph ();
	} else if ( option == 0 ) {
		read_adj_mat ();
	} else {
		cout << "Invalid option\n";
		system ( "pause" );
		return 0;
	}

	//In ra ma trận kề vừa Đọc (or) Tạo: 
	dis_adj_mat ();

	//Duyệt từ nút thứ: 
	cout << "\nnode = "; cin >> node;

	//Khởi tạo lại tất cả visited[i] là chưa xét:
	for ( int i = 1; i <= ver; i++ ) {
		visited[i] = false;
	}

	// Duyệt stack:
	cout << "\nDFS_stack(" << node << ") : ";
	DFS_stack ( node );

	cout << "\n";
	return 0;
}

/*
Options:

0 - Read From File

1 - Random Graph

Your option: 1
------------------------------------------------------------
Vertex = 13
Density = 0.15

Created random graph with density 0.15 vs actual density is:  0.153846:

0 0 0 0 1 1 0 1 0 0 0 1 0
0 0 1 1 0 0 0 0 0 0 0 0 0
0 1 0 0 1 0 0 0 0 0 0 0 0
0 1 0 0 0 0 0 1 0 0 0 0 0
1 0 1 0 0 0 0 0 0 0 0 0 0
1 0 0 0 0 0 0 0 1 0 1 0 0
0 0 0 0 0 0 0 1 1 0 0 0 0
1 0 0 1 0 0 1 0 0 0 0 0 0
0 0 0 0 0 1 1 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 1 0 0 0 0 0 0 0
1 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0

node = 1

DFS_stack(1) : 1 5 3 2 4 8 7 9 6 11 12
*/