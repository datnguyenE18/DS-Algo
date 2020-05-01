#include<bits/stdc++.h>
using namespace std;

class Graph {//định nghĩa lớp Graph
	int V; // tập đỉnh V của đồ thị
	list<int> *adj; // con trỏ đến mảng các danh sách kề
	public:
	Graph ( int V ); // Constructor của lớp
	void addEdge ( int v, int w ); // thêm một cạnh vào đồ thị
	void printGraph ();//in ra danh sách kề
};

Graph::Graph ( int V ) {
	this->V = V;
	adj = new list<int>[V];
}

void Graph::addEdge ( int v, int w ) {
	adj[v].push_back ( w ); // thêm đỉnh w vào list(v).
	adj[w].push_back ( v ); // Đồ thị vô hướng: thêm đỉnh v vào list(w).
}

void Graph::printGraph () {
	int v; list<int>::iterator i;
	for ( v = 1; v < V; ++v ) {
		cout << "\n Danh sach ke cua dinh " << v << "\n head "; // Danh sách kề của đỉnh
		for ( i = adj[v].begin (); i != adj[v].end (); ++i )
			cout << "-> " << *i;
		cout << endl;
	}
}

int main () {
	ifstream fp ( "dothi.in" ); int n, m, dau, cuoi;
	fp >> n >> m; Graph gh ( n + 1 );
	for ( int i = 1; i <= m; i++ ) {
		fp >> dau >> cuoi;
		gh.addEdge ( dau, cuoi );
	}
	fp.close ();
	gh.printGraph ();
	system ( "pause" );
}