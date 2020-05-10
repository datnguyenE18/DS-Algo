#include <iostream>
#include <stack>
using namespace std;
#define NODE 13

int graph[NODE][NODE];
int transGraph[NODE][NODE];

void transpose() {
    for ( int i = 0; i < NODE; i++ )
        for ( int j = 0; j < NODE; j++ )
            transGraph[i][j] = graph[j][i];
}

void traverse(int g[NODE][NODE], int u, bool visited[]) {
    visited[u] = true;
    cout << u + 1 << " ";
    for ( int v = 0; v < NODE; v++ ) {
        if ( g[u][v] ) {
            if ( !visited[v] )
                traverse(g, v, visited);
        }
    }
}

void topoSort(int u, bool visited[], stack<int> &stk) {
    visited[u] = true;
    for ( int v = 0; v < NODE; v++ ) {
        if ( graph[u][v] ) {
            if ( !visited[v] )
                topoSort(v, visited, stk);
        }
    }
    stk.push(u);
}

void getStrongConComponents() {
    stack<int> stk;
    bool vis[NODE];
    for ( int i = 0; i < NODE; i++ )
        vis[i] = false;
    for ( int i = 0; i < NODE; i++ )
        if ( !vis[i] )
            topoSort(i, vis, stk);
    for ( int i = 0; i < NODE; i++ )
        vis[i] = false;
    transpose();
    while ( !stk.empty() ) {
        int v = stk.top(); stk.pop();
        if ( !vis[v] ) {
            traverse(transGraph, v, vis);
            cout << endl;
        }
    }
}

int main() {
    for ( int i = 0; i < NODE; i++ ) {
        for ( int j = 0; j < NODE; j++ ) {
            cin >> graph[i][j];
        }
    }
    cout << "Following are strongly connected components in given graph: " << endl;
    getStrongConComponents();
}

/*
0 0 0 0 0 1 0 0 0 0 0 0 0
0 0 1 0 0 0 0 1 0 0 0 0 0
0 0 0 0 0 0 0 0 1 0 0 0 1
1 0 0 0 0 1 0 0 0 0 0 0 0
0 0 0 0 0 0 1 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 1 0 1 0
0 0 0 0 0 0 0 0 0 0 1 0 1
0 0 0 1 0 0 0 0 0 0 0 1 0
0 0 0 0 1 0 1 0 0 0 0 0 0
0 1 1 0 0 0 0 0 0 0 0 0 0
0 1 0 0 0 0 0 1 0 0 0 0 0
0 0 0 1 0 0 0 0 0 1 0 0 0
0 0 0 0 0 0 0 0 1 0 1 0 0
Following are strongly connected components in given graph:
1 4 8 2 10 6 12 11 7 5 9 3 13
*/