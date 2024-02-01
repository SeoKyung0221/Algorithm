#include<bits/stdc++.h>
using namespace std;
int te, n, m, a, b, visited[1004];
vector<int> adj[1004];

void dfs(int here){
	visited[here] = 1;
	
	for(int to : adj[here]){
		if(!visited[to]){
			dfs(to);
		}
	}
	return;
}
int main(){
	cin >> te;
	while(te--){
		fill(visited, visited + 1004, 0);
		for(int i = 0; i < 1004; i++){
			adj[i].clear();
		}
		
		cin >> n >> m;
		for(int i = 0; i < m; i++){
			cin >> a >> b;
			adj[a].push_back(b);
			adj[b].push_back(a);
		}
		
		int cnt = 0;
		
		for(int i = 1; i <= n; i++){
			if(!visited[i]){
				dfs(i);
				cnt++;
			}
		}
		if(m == n - 1 && cnt == 1) cout << "tree\n";
		else cout << "graph\n";
	}
}