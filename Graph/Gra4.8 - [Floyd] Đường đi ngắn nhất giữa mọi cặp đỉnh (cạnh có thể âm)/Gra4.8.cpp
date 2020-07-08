#include<bits/stdc++.h>
using namespace std;
#define MAX 100

int ver,
	adj_mat[MAX][MAX], d[MAX][MAX], next0[MAX][MAX];

void read_adj_mat() {
	ifstream FileIn;
	FileIn.open("graph.dat", ios_base::in);

	FileIn >> ver;
	for ( int i = 1; i <= ver; i++ )
		for ( int j = 1; j <= ver; j++ )
			FileIn >> adj_mat[i][j];

	FileIn.close();
	cout << "Read adjacency matrix from a file: \n\n";
}

void dis_adj_mat() {
	for ( int i = 1; i <= ver; i++ ) {
		for ( int j = 1; j <= ver; j++ ) {
			if ( adj_mat[i][j] == 999 )
				cout << "inf" << "  ";
			else cout << " " << adj_mat[i][j] << "   ";
		} cout << "\n\n";
	}
}

void init() {
	for ( int i = 1; i <= ver; i++ )
		for ( int j = 1; j <= ver; j++ ) {
			d[i][j] = adj_mat[i][j];
			next0[i][j] = j;
		}
}

void ReconstructPath(int u, int v) {
	int length = 0;
	if ( next0[u][v] == 999 ) {
		cout << "No path !";
	} else {
		cout << u << " ";
		while ( u != v ) {
			length += d[u][next0[u][v]];
			u = next0[u][v];
			cout << u << " ";
		}
	}
	cout << "	( length = " << length << " )";
}

void floyd() {
	for ( int k = 1; k <= ver; k++ ) {
		for ( int i = 1; i <= ver; i++ )
			for ( int j = 1; j <= ver; j++ )
				if ( d[i][j] > d[i][k] + d[k][j] ) {
					d[i][j] = d[i][k] + d[k][j];
					next0[i][j] = next0[i][k];
				}
	}

	for ( int i = 1; i <= ver; i++ )
		for ( int j = 1; j <= ver; j++ ) {
			cout << "(" << i << "," << j << "): ";
			ReconstructPath(i, j);
			cout << endl;
		}
}

int main() {
	read_adj_mat();
	dis_adj_mat();
	init();
	floyd();
}

/*
Read adjacency matrix from a file:

 0    1   inf  inf  inf  inf

inf   0    5    2   inf   7

inf  inf   0   inf  inf   1

 2   inf   1    0    4   inf

inf  inf  inf   3    0   inf

inf  inf  inf  inf   1    0

(1,1): 1        ( length = 0 )
(1,2): 1 2      ( length = 1 )
(1,3): 1 2 4 3  ( length = 4 )
(1,4): 1 2 4    ( length = 3 )
(1,5): 1 2 4 3 6 5      ( length = 6 )
(1,6): 1 2 4 3 6        ( length = 5 )
(2,1): 2 4 1    ( length = 4 )
(2,2): 2        ( length = 0 )
(2,3): 2 4 3    ( length = 3 )
(2,4): 2 4      ( length = 2 )
(2,5): 2 4 3 6 5        ( length = 5 )
(2,6): 2 4 3 6  ( length = 4 )
(3,1): 3 6 5 4 1        ( length = 7 )
(3,2): 3 6 5 4 1 2      ( length = 8 )
(3,3): 3        ( length = 0 )
(3,4): 3 6 5 4  ( length = 5 )
(3,5): 3 6 5    ( length = 2 )
(3,6): 3 6      ( length = 1 )
(4,1): 4 1      ( length = 2 )
(4,2): 4 1 2    ( length = 3 )
(4,3): 4 3      ( length = 1 )
(4,4): 4        ( length = 0 )
(4,5): 4 3 6 5  ( length = 3 )
(4,6): 4 3 6    ( length = 2 )
(5,1): 5 4 1    ( length = 5 )
(5,2): 5 4 1 2  ( length = 6 )
(5,3): 5 4 3    ( length = 4 )
(5,4): 5 4      ( length = 3 )
(5,5): 5        ( length = 0 )
(5,6): 5 4 3 6  ( length = 5 )
(6,1): 6 5 4 1  ( length = 6 )
(6,2): 6 5 4 1 2        ( length = 7 )
(6,3): 6 5 4 3  ( length = 5 )
(6,4): 6 5 4    ( length = 4 )
(6,5): 6 5      ( length = 1 )
(6,6): 6        ( length = 0 )
*/