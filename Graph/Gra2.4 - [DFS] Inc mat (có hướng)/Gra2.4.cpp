#include<bits/stdc++.h>
using namespace std;

int ver, //số đỉnh
	edg, //số cạnh
	adj_mat[100][100], // Mảng 2 chiều lưu ma trận kề
	inc_mat[100][100], // Mảng 2 chiều lưu ma liên thuộc
	visited[100],//Lưu tình trạng duyệt của node
	i, j, node;
double density; // density = ratio between #edges / N^2 - tỉ lệ cạnh


//Hàm sinh số ngẫu nhiên trong khoảng [0 , 1]:
double prob () {
	return ( double ) rand () / RAND_MAX;
}

//Hàm tạo ma trận kề ngẫu nhiên từ ver và density cho trước
void rand_graph () {
	edg = 0;

	for ( i = 0; i < ver; i++ ) {
		for ( j = 0; j < ver; j++ )
			adj_mat[i][j] = 0;
	}

	for ( i = 0; i < ver; i++ ) {
		for ( j = i + 1; j < ver; j++ ) {
			if ( prob () < density && adj_mat[j][i] != 1 ) {
				adj_mat[i][j] = 1;
				edg++;
			}
		}
	}
}

//Chuyển sang ma trận liên thuộc
void Trans_2_Inc_mat () {
	edg = 0;
	for ( i = 1; i <= ver; i++ ) {
		for ( j = 1; j <= ver; j++ ) {
			if ( adj_mat[i][j] ) {
				inc_mat[i][edg] = 1;
				inc_mat[j][edg] = -1;
				edg++;
			}
		}
	}
}

//In ra ma trận liên thuộc vừa Tạo
void dis_inc_mat () {
	cout << endl << " Created random Inc matrix with density " << density << " vs actual density is:  " << ( double ) 2 * edg / ( ver*ver ) << endl;
	for ( i = 1; i <= ver; i++ ) {
		for ( j = 1; j <= edg - 1; j++ ) {
			if ( inc_mat[i][j] == -1 ) cout << inc_mat[i][j] << " ";
			else cout << " " << inc_mat[i][j] << " ";
		} cout << "\n";
	}
}

//DFS sử dụng đệ quy:
void DFS_dequi ( int node ) {
	cout << node << " ";
	visited[node] = 1;
	for ( int j = 1; j <= edg; j++ ) {
		if ( inc_mat[node][j] == 1 ) {
			for ( int i = 1; i <= ver; i++ ) {
				if ( inc_mat[i][j] == -1 && visited[i] == 0 ) { 
					DFS_dequi ( i );
				}
			}
		}
	}
}

//DFS sử dụng stack
void DFS_stack ( int node ) {
	int stack0[100], 
		index = 1, 
		s; 
	stack0[index] = node; 
	cout << node << " "; 
	visited[node] = 1; 
	while ( index > 0 ) {
		s = stack0[index]; 
		index--; 
		for ( i = 1; i <= edg; i++ ) { 
			int z = 0;
			if ( inc_mat[s][i] == 1 ) {
				for ( j = 1; j <= ver; j++ ) {
					if ( inc_mat[j][i] == -1 && visited[j] == 0 ) {
						z = 1;
						cout << j << " ";
						visited[j] = 1;
						index++;
						stack0[index] = s;
						index++;
						stack0[index] = j;
						break;
					}
				}
			}
			if ( z == 1 ) break;
		}
	}
}

int main () {
	cout << "Vertex = "; cin >> ver;
	cout << "Density = "; cin >> density;

	//Tạo ngẫu nhiên ma trận kề:
	rand_graph ();

	//Chuyển sang man trận liên thuộc
	Trans_2_Inc_mat ();

	//In ra ma trận liên thuộc vừa Tạo: 
	dis_inc_mat ();

	for ( int i = 1; i <= ver; i++ ) {
		visited[i] = 0;
	}

	cout << "\nnode = "; cin >> node;

	cout << "\nDFS_dequi(" << node << ") : ";
	DFS_dequi ( node );
	cout << "\n";

	for ( int i = 1; i <= ver; i++ ) {
		visited[i] = 0;
	}

	cout << "\nDFS_stack(" << node << ") : ";
	DFS_stack ( node );

	cout << "\n";
	return 0;
}

/*
Density = 0.2

Created random Inc matrix with density 0.2 vs actual density is:  0.19
 1  1  1  1  1  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0
 0  0  0  0  0  1  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0
 0  0  0  0  0  0  1  1  1  1  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0
 0  0  0  0  0  0  0  0  0  0  1  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0
-1  0  0  0  0  0  0  0  0  0  0  1  1  1  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0
 0 -1  0  0  0  0  0  0  0  0  0  0  0  0  1  1  1  1  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0
 0  0 -1  0  0  0  0  0  0  0  0 -1  0  0  0  0  0  0  1  1  1  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0
 0  0  0  0  0  0  0  0  0  0  0  0  0  0 -1  0  0  0  0  0  0  1  1  0  0  0  0  0  0  0  0  0  0  0  0  0  0
 0  0  0  0  0  0 -1  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  1  0  0  0  0  0  0  0  0  0  0  0  0  0
 0  0  0  0  0  0  0  0  0  0  0  0  0  0  0 -1  0  0 -1  0  0  0  0 -1  1  0  0  0  0  0  0  0  0  0  0  0  0
 0  0  0  0  0 -1  0 -1  0  0  0  0  0  0  0  0  0  0  0 -1  0  0  0  0  0  1  1  1  0  0  0  0  0  0  0  0  0
 0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  1  1  1  0  0  0  0  0  0
 0  0  0 -1  0  0  0  0 -1  0  0  0  0  0  0  0  0  0  0  0  0 -1  0  0  0  0  0  0  0  0  0  1  0  0  0  0  0
 0  0  0  0  0  0  0  0  0 -1 -1  0  0  0  0  0  0  0  0  0 -1  0  0  0  0 -1  0  0  0  0  0  0  0  0  0  0  0
 0  0  0  0  0  0  0  0  0  0  0  0 -1  0  0  0 -1  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  1  1  1  0  0
 0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0 -1  0 -1  0  0  0 -1  0  0  0  0  0  0  0  0
 0  0  0  0 -1  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0 -1  0  0  0  0  0 -1  0  0  1  0
 0  0  0  0  0  0  0  0  0  0  0  0  0 -1  0  0  0 -1  0  0  0  0  0  0  0  0  0  0  0 -1  0  0  0 -1  0 -1  1
 0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0 -1  0  0 -1 -1  0  0 -1  0 -1
 0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0

node = 1

DFS_dequi(1) : 1 5 7 10 16 11 14 17 18 19 15 6 8 13

DFS_stack(1) : 1 5 7 10 16 11 14 17 18 19 15 6 8 13
*/