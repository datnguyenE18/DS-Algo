#include<bits/stdc++.h>
using namespace std;
#define MAX 1001

int ver, adj_mat[MAX][MAX], par[MAX];

void read_adj_mat() {
	ifstream FileIn;
	FileIn.open("graph.dat", ios_base::in);
	FileIn >> ver;

	for ( int i = 1; i <= ver; i++ ) {
		for ( int j = 1; j <= ver; j++ )
			FileIn >> adj_mat[i][j];
	}

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

// Tìm gốc của đỉnh i:
int find(int u) {
	while ( par[u] != u )
		u = par[u];
	return u;
}

// Nếu u và v chung gốc thì trả về false
void union1(int u, int v) {
	int i = find(u);
	int j = find(v);
	par[i] = j;
}

void kruskal() {
	//Khởi tạo giá trị cây khung nhỏ nhất:
	int cost { 0 };

	// Khởi tạo gốc của các đỉnh (khi nó chưa nối với đỉnh nào thì gốc của nó là chính nó)
	for ( int i = 1; i <= ver; i++ )
		par[i] = i;

	int count { 0 };
	cout << "\nMinimum spanning tree of the graph:\n";
	while ( count < ver - 1 ) {
		int min { 999 }, a { -1 }, b { -1 };
		for ( int i = 1; i <= ver; i++ ) {
			for ( int j = 1; j <= ver; j++ ) {
				if ( find(i) != find(j) && adj_mat[i][j] < min ) {
					min = adj_mat[i][j];
					a = i;
					b = j;
				}
			}
		}
		union1(a, b);
		cout << a << " - " << b << "	: " << min << endl;
		count++;
		cost += min;
	}
	cout << "\n=> MSTweight : " << cost << endl;
}

int main() {
	read_adj_mat();
	dis_adj_mat();
	kruskal();
}

/*
Read adjacency matrix from a file:

inf   2    1    3   inf  inf  inf  inf  inf  inf  inf  inf  inf

 2   inf   2   inf  inf   5    5   inf  inf  inf  inf  inf  inf

 1    2   inf   4   inf   5   inf  inf  inf  inf  inf  inf  inf

 3   inf   4   inf   5    5   inf  inf  inf  inf  inf  inf  inf

inf  inf  inf   5   inf   6   inf  inf  inf   6   inf  inf  inf

inf   5    5    5    6   inf   6    6    6    6   inf  inf  inf

inf   5   inf  inf  inf   6   inf   6   inf  inf  inf  inf  inf

inf  inf  inf  inf  inf   6    6   inf   7   inf  inf   7    7

inf  inf  inf  inf  inf   6   inf   7   inf   7    7   inf  inf

inf  inf  inf  inf   6    6   inf  inf   7   inf   7    7   inf

inf  inf  inf  inf  inf  inf  inf  inf   7    7   inf   8   inf

inf  inf  inf  inf  inf  inf  inf   7   inf   7    8   inf   8

inf  inf  inf  inf  inf  inf  inf   7   inf  inf  inf   8   inf


Minimum spanning tree of the graph:
1 - 3   : 1
1 - 2   : 2
1 - 4   : 3
2 - 6   : 5
2 - 7   : 5
4 - 5   : 5
5 - 10  : 6
6 - 8   : 6
6 - 9   : 6
8 - 12  : 7
8 - 13  : 7
9 - 11  : 7

=> MSTweight : 60
*/