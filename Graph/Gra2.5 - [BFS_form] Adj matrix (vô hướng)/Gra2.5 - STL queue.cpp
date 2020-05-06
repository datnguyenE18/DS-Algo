#include<bits/stdc++.h>
using namespace std;

int ver, //số đỉnh
adj_mat[100][100], // Mảng 2 chiều lưu ma trận kề
visited[100],//Lưu tình trạng duyệt của node
i, j, node;
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

//BFS queue:
void BFS_queue ( int node ) {
	queue<int>queue0;
	queue0.push ( node );
	visited[node] = 1;

	while ( !queue0.empty () ) {
		int s = queue0.front ();
		cout << s << " ";
		queue0.pop ();
		for ( int i = 1; i <= ver; i++ ) {
			if ( visited[i] == 0 && adj_mat[s][i] == 1 ) {
				queue0.push ( i );
				visited[i] = 1;
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

	//ban đầu gán tất cả là chưa xét:
	for ( int i = 1; i <= ver; i++ ) {
		visited[i] = 0;
	}

	//Duyệt từ nút thứ: 
	cout << "\nnode = "; cin >> node;

	// Duyệt hàng đợi:
	cout << "\nBFT_queue(" << node << ") : ";
	BFS_queue ( node );
	cout << "\n";


	cout << "\n";
	return 0;
}

/*
Options:

0 - Read From File

1 - Random Graph

Your option: 0
------------------------------------------------------------
Read adjacency matrix from a file:

0 1 1 0 0 0 0 0 0 0 1 0 0
1 0 0 1 0 1 0 0 0 0 0 0 0
1 0 0 1 0 0 0 0 0 0 0 0 0
0 1 1 0 0 1 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 1 1 0 0 0
0 1 0 1 0 0 1 1 0 0 0 0 0
0 0 0 1 0 1 0 1 0 0 0 0 0
0 0 0 0 0 1 0 0 0 1 0 0 0
0 0 0 0 1 0 0 0 0 0 0 0 1
0 0 0 0 1 0 0 1 0 0 0 0 0
1 0 0 0 0 0 0 0 0 0 0 1 1
0 0 0 0 0 0 0 0 0 0 1 0 1
0 0 0 0 0 0 0 0 1 0 1 1 0

node = 1

BFT_queue(1) : 1 2 3 11 4 6 12 13 7 8 9 10 5
*/