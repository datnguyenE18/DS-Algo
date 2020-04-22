#include <bits/stdc++.h>
using namespace std;

int **G, // ma trận kề
	**G_lt, // G liên thuộc
	N, M, // số đỉnh, số cạnh
	i, j;

void Doc_file ( string filename ) {
	ifstream infile;
	infile.open ( filename );
	infile >> N;

	G = new int*[N];
	for ( i = 0; i < N; i++ ) {
		G[i] = new int[N];
		for ( j = 0; j < N; j++ )
			infile >> G[i][j];
	} infile.close ();
}

void G_ke2lienthuoc () {
	// 3 steps:
	// -- (1) count number of edges
	// -- (2) create G_lt
	// -- (3) assign G_lt from adjacency matrix

	int edge_index = 0;
	for ( i = 0; i < N; i++ ) {
		for ( j = i + 1; j < N; j++ ) {
			if ( G[i][j] )
				edge_index++;
		}
	}

	M = edge_index;    // sum of edges

	G_lt = new int*[N];
	for ( i = 0; i < N; i++ ) {
		G_lt[i] = new int[M];
		for ( j = 0; j < M; j++ )
			G_lt[i][j] = 0;
	}

	// assign G_lt from adjancent matrix
	edge_index = 0;
	for ( i = 0; i < N; i++ ) {
		for ( j = i + 1; j < N; j++ ) {
			if ( G[i][j] > 0 ) {
				G_lt[i][edge_index] = 1;
				G_lt[j][edge_index] = 1;
				edge_index++;
			}
		}
	}

}


void Print_matrix ( int **G1, int N1, int M1 ) {
	cout << " | ";
	for ( i = 0; i < M1; i++ )
		cout << i + 1 << " ";
	cout << "\n" << "-|---------------------------\n";

	for ( i = 0; i < N1; i++ ) {
		cout << i + 1 << "| ";
		for ( j = 0; j < M1; j++ )
			cout << G1[i][j] << " ";
		cout << "\n";
	}
}


int main () {
	string filename = "graph.dat";
	Doc_file ( filename );
	cout << " Ma tran ke cua graph : \n" << endl;
	Print_matrix ( G, N, N );
	cout << " \n\n Ma tran lien thuoc cua graph : \n" << endl;
	G_ke2lienthuoc ();
	Print_matrix ( G_lt, N, M );

	system ( "pause" );
}