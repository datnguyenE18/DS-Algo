#include<bits/stdc++.h>
using namespace std;
#define MAX 1001

int ver, // Số đỉnh của đồ thị
	adj_mat[MAX][MAX], // mảng 2 chiều lưu ma trận kề
	Cy[MAX], // mảng lưu chu trình Hamilton
	count0;
bool visited[MAX];

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
		for ( int j = 1; j <= ver; j++ )
			cout << adj_mat[i][j] << " ";
		cout << endl;
	}
}

void init() {
	for ( int i = 1; i <= ver; i++ )
		visited[i] = false;
	cout << "First point = ";  cin >> Cy[0];
	count0 = 0;
}

void Result() {
	cout << "\n";
	for ( int i = ver; i >= 0; i-- )
		cout << Cy[i] << " ";
	count0++;
}

void Hamilton(int i) {
	for ( int j = 1; j <= ver; j++ ) {
		if ( adj_mat[Cy[i - 1]][j] == 1 && visited[j] == false ) {
			Cy[i] = j;
			visited[j] = true;
			if ( i < ver ) Hamilton(i + 1);
			else if ( Cy[i] == Cy[0] ) Result();
			visited[j] = false;
		}
	}
}

int main() {
	read_adj_mat();
	dis_adj_mat();
	init();
	cout << "\nHamiltonian Circuits from " << Cy[0] << ": ";
	Hamilton(1);
	if ( count0 == 0 ) cout << "\nCan not find Hamiltonian Cycle\n";
}

/*
Read adjacency matrix from a file:

0 1 0 1 0
1 0 1 0 1
0 1 0 1 1
1 0 1 0 1
0 1 1 1 0
First point = 1

Hamiltonian Circuits from 1:
1 4 5 3 2 1
1 4 3 5 2 1
1 2 5 3 4 1
1 2 3 5 4 1
*/