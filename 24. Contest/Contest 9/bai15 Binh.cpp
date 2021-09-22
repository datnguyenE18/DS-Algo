#include <bits/stdc++.h>
using namespace std;

int n, e, u, v;
vector < int > *adj;
vector < bool > isOK(1001);

void DFS(int s)
{
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
        cin >> n >> e;
        adj = new vector <int> [1001];
        for (int i = 1; i <= e; i++)
        {
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        refresh();
        int num = 0;
        for (int i = 1; i <= n; i++)
            if(isOK[i])
            {
                num ++;
                DFS(i);
            }
        cout << num << endl;
        delete[] adj;
    }
}