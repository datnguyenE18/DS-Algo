#include <bits/stdc++.h>
using namespace std;

class Edge {
	public:
	int source;
	int dest;
	int weight;
};

bool cmp(Edge a, Edge b) {
	return a.weight < b.weight;
}

int findParent(int v, int *parent) { //find parent vertex of vertex v
	if ( parent[v] == v )
		return v;
	return findParent(parent[v], parent);
}

void Kruskal(Edge *input, int n, int E) {
	sort(input, input + E, cmp); //Sort all edges by ascending order
	Edge *output = new Edge[n - 1];
	int *parent = new int[n];
	for ( int i = 1; i <= n; i++ )
		parent[i] = i; //initialize all vertices' parent equal to themselves
	int count = 0;
	int i = 0;
	while ( count != n - 1 ) {
		Edge currentEdge = input[i];
		//Check if current Edge can make a cycle
		int sourceParent = findParent(currentEdge.source, parent);
		int destParent = findParent(currentEdge.dest, parent);
		if ( sourceParent != destParent ) { //two vertices of currentEdge is inequal
			output[count] = currentEdge;
			count++;
			parent[sourceParent] = destParent; //Re-assign parent
		}
		i++;
	}
	int MSTlength = 0;
	for ( int i = 0; i < n - 1; i++ ) { //Print MST
		MSTlength += output[i].weight;
		/*if(output[i].source < output[i].dest)
			cout << setw(2) << output[i].source
				 << setw(3) << output[i].dest<< ": "
				 << setw(2) << output[i].weight << endl;
		else
			cout << setw(2) << output[i].dest
				 << setw(3) << output[i].source<< ": "
				 << setw(2) << output[i].weight << endl;*/
	}
	cout << MSTlength << endl;
}

int main() {
	int t;
	cin >> t;
	while ( t-- ) {
		int n, E;
		cin >> n >> E;
		Edge *input = new Edge[E];
		int edgeCount = 0;
		for ( int i = 0; i < E; i++ ) {
			int s, d, w;
			cin >> s >> d >> w;
			input[i].source = s;
			input[i].dest = d;
			input[i].weight = w;
		}
		Kruskal(input, n, E);
	}
	return 0;
}

/*
2
3 3
1 2 5
2 3 3
1 3 1
4
2 1
1 2 5
5
*/