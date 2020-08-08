#include <bits/stdc++.h>
using namespace std;
#define MAX 100

int ver, st,
	adj_mat[MAX][MAX], d[MAX * MAX], pre[MAX * MAX];

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
	cout << "The Starting Point: "; cin >> st;
	pre[st] = 0;
	for ( int i = 1; i <= ver; i++ )
		d[i] = adj_mat[st][i];
}

void bellman_ford() {
	cout << "\nLoop:\n";
	for ( int k = 1; k <= ver - 2; k++ ) { // xét (n - 1) lần lặp; n là số đỉnh
		cout << "K = " << k << ": ";
		for ( int v = 1; v <= ver; v++ ) { // Duyệt qua n đỉnh...
			if ( v != st ) { // ... trử đỉnh gốc
				for ( int u = 1; u <= ver; u++ ) { //Tiếp tục duyệt qua n đỉnh
					if ( adj_mat[u][v] != 0 && d[u] != 999 && d[u] + adj_mat[u][v] < d[v] ) {
						d[v] = d[u] + adj_mat[u][v];
						pre[v] = u;
					}
				}
			}
		}
		for ( int i = 1; i <= ver; i++ ) {
			cout << "[" << d[i] << "," << pre[i] << "]" << " ";
		}
		cout << endl;
	}
	cout << "\n\n";
	for ( int i = 1; i <= ver; i++ ) {
		if ( pre[i] == 0 && i != st )
			cout << "- pre[" << i << "]: " << st << endl;
		else cout << "- pre[" << i << "]: " << pre[i] << endl;
	}
	cout << endl;
	for ( int i = 1; i <= ver; i++ ) {
		cout << "The distance from " << st << " to " << i << " is	: " << d[i] << endl;
	}
}
int main() {
	read_adj_mat();
	dis_adj_mat();
	init();
	bellman_ford();
}

/*
Read adjacency matrix from a file:

 0    1   inf  inf   3

inf   0    3    3    8

inf  inf   0    1    -5

inf  inf   2    0   inf

inf  inf  inf   4    0

The Starting Point: 1

Loop:
K = 1: [0,0] [1,0] [4,2] [4,2] [-1,3]
K = 2: [0,0] [1,0] [4,2] [3,5] [-1,3]
K = 3: [0,0] [1,0] [4,2] [3,5] [-1,3]


- pre[1]: 0
- pre[2]: 1
- pre[3]: 2
- pre[4]: 5
- pre[5]: 3

The distance from 1 to 1 is     : 0
The distance from 1 to 2 is     : 1
The distance from 1 to 3 is     : 4
The distance from 1 to 4 is     : 3
The distance from 1 to 5 is     : -1
*/