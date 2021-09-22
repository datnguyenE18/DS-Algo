#include <bits/stdc++.h>
using namespace std;

struct edge
{
    int first, last;
};

int V, E, timer, low[10000], num[10000], parent[10000];
vector <int> *adj;

void init()
{
    timer = 0;
    int u, v;
    cin >> V >> E;
    adj = new vector <int> [V+1];
    for (int i = 1; i <= E; i++)
    {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i = 1; i <= V; i++) parent[i] = 0;
    
}

void DFS(int u)
{
    num[u] = low[u] = timer++;
    for (int v : adj[u])
    {
        if (v != parent[u])
        {
            if(parent[v] == 0)
            {
                parent[v] = u;
                DFS(v);
                low[u] = min(low[u], low[v]);
            }
            else low[u] = min(low[u], num[v]);
        }
    }
}

bool compare(const edge& a, const edge& b)
{
    if (a.first < b.first) return true;
    if (a.first > b.first) return false;
    if (a.last < b.last) return true;
    return false;
}

void showBridges()
{
    edge bridges[10000];
    int counts = 0;
    for (int i = 1; i <= V; i++)
        if (parent[i] != -1 && low[i] >= num[i])
        {
            bridges[counts].first = min(i, parent[i]);
            bridges[counts].last = max(i, parent[i]);
            counts++;
        }
    sort(bridges, bridges + counts, compare);
    for (int i = 0; i < counts; i++) cout << bridges[i].first << " " << bridges[i].last << " "; 
    cout << endl;
}

main()
{
    int T;
    cin >> T;
    while (T--)
    {
        init();
        for (int i = 1; i <= V; i++)
            if (parent[i] == 0)
            {
                parent[i] = -1;
                DFS(i);
            } 
        showBridges();
    }
}