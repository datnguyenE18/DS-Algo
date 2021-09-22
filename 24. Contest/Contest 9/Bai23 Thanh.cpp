#include <bits/stdc++.h>
using namespace std;
#define IOS() ios_base::sync_with_stdio(0);cin.tie(0); cout.tie(0);
typedef long long int ll;
const long long mod = 1e9 + 7;
int v,e,a,b;
vector <vector<int> > adj;
bool visited[1000];

bool DFS(int u){
	stack <int> st;
	st.push(u);
	visited[u]=false;
	vector <int> parent(1005,-1);
	while(st.size()>0){
		int s = st.top(); st.pop();
		for(int t = 0 ; t < adj[s].size() ; t++){
			if(visited[adj[s][t]]){
				visited[adj[s][t]]=false;
				st.push(s);
				st.push(adj[s][t]);
				parent[adj[s][t]]=s;
			}
			else if(parent[s]!=adj[s][t]) return true;
		}
	}
	return false;
}
bool DFS_dequy(int u, int parent){
	visited[u]=false;
	for(int i = 0 ; i < adj[u].size(); i++){
		if(visited[adj[u][i]]){
			if(DFS_dequy(adj[u][i],u)) return true;
		}
		else if(adj[u][i]!=parent) return true;
	}
	return false;
}
bool cycle(){
	adj.clear();
	cin>>v>>e;
	memset(visited,true,sizeof(visited));
	adj.resize(1005);
	for(int i = 0 ; i < e ; i++){
		cin>>a>>b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	for(int i = 1; i <= v; i++){
		if(visited[i]){
			if(DFS_dequy(i,-1)) return true;
		}
	}
	return false;
}
main()
{
//	IOS()
	int T;
	cin>>T;
	while(T--){
		if(cycle()) cout<<"YES\n";
		else cout<<"NO\n";	
	}
	return 0;
}
// hii

