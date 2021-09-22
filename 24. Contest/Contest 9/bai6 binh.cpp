#include <bits/stdc++.h>
using namespace std;

int n, e, u, v, s;
vector < int > *adj;
vector < bool > isOK(10000);

void DFS(int s)
{
    cout << s << " ";
    isOK[s] = false;
    for (int i = 0; i < adj[s].size(); i++)
        if(isOK[adj[s][i]]) DFS(adj[s][i]);
}

void refresh()
{
    for (int i = 1; i <= n; i++) isOK[i] = true;
}

main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n >> e >> s;
        adj = new vector < int > [n+1];
        for (int i = 1; i <= e; i++)
        {
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        refresh();
        DFS(s);
        cout << endl;
    }
}