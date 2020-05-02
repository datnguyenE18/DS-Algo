#include<bits/stdc++.h>
using namespace std;

int ver,
visited[100],
node,
i, j;
double density;
vector<int> adj_list[100];

//Hàm sinh số ngẫu nhiên trong khoảng [0 , 1]:
double prob () {
	return ( double ) rand () / RAND_MAX;
}

//Sinh ngẫu nhiên danh sách kề:
void rand_adj_list () {
	int edge = 0;
	for ( i = 1; i <= ver; i++ ) {
		for ( j = i + 1; j <= ver; j++ ) {
			if ( prob () < density ) {
				adj_list[i].push_back ( j );
				adj_list[j].push_back ( i );
				edge++;
			}
		}
	}
	cout << "\n Created random list with density " << density << " vs actual density is:  " << ( double ) 2 * edge / ( ver*ver ) << ":\n\n";
}


//In danh sách kề vừa tạo
void dis_adj_list () {
	for ( int i = 1; i <= ver; i++ ) {
		cout << "Adj{" << i << "}	={";
		for ( int j = 0; j < adj_list[i].size (); j++ ) {
			cout << adj_list[i][j];
			if ( j == adj_list[i].size () - 1 )	break;
			cout << ",";
		}
		cout << "}" << endl;
	}
	cout << endl;
}

//Duyệt theo Đệ quy
void DFS_dequi ( int node ) {
	cout << node << " ";
	visited[node] = 1;
	for ( int j = 0; j < adj_list[node].size (); j++ ) {
		if ( visited[adj_list[node][j]] == 0 )
			DFS_dequi ( adj_list[node][j] );
	}
}

int main () {
	cout << "Vertex = "; cin >> ver;
	cout << "Density = "; cin >> density;

	//Tạo ngẫu nhiên danh sách kề:
	rand_adj_list ();

	//In ra danh sách kề vừa tạo:
	dis_adj_list ();

	//Khởi tạo tất cả visited[i] là chưa xét:
	for ( i = 1; i <= ver; i++ ) {
		visited[i] = 0;
	}

	// Duyệt từ nút thứ :
	cout << "\nnode = "; cin >> node;

	// Duyệt đệ quy:
	cout << "\nDFS_dequi(" << node << ") : ";
	DFS_dequi ( node );
	cout << "\n";

	return 0;
}

/*
Vertex = 20
Density = 0.2

Created random list with density 0.2 vs actual density is:  0.22:

Adj{1}  ={2,4,12,17,18,20}
Adj{2}  ={1,3,6,7,8,14,18}
Adj{3}  ={2,12}
Adj{4}  ={1,10,12,14,15}
Adj{5}  ={15}
Adj{6}  ={2,8,16,19}
Adj{7}  ={2,9,11,16,19}
Adj{8}  ={2,6,11,12,15}
Adj{9}  ={7,14,17}
Adj{10} ={4,11}
Adj{11} ={7,8,10,17}
Adj{12} ={1,3,4,8,15,18,20}
Adj{13} ={17,19,20}
Adj{14} ={2,4,9,20}
Adj{15} ={4,5,8,12}
Adj{16} ={6,7,18,19,20}
Adj{17} ={1,9,11,13}
Adj{18} ={1,2,12,16,19}
Adj{19} ={6,7,13,16,18,20}
Adj{20} ={1,12,13,14,16,19}


node = 1

DFS_dequi(1) : 1 2 3 12 4 10 11 7 9 14 20 13 17 19 6 8 15 5 16 18
*/