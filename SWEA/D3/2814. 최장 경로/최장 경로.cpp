#include<bits/stdc++.h>
using namespace std;
int te, tcnt, n, m, a, b, ret, visited[14];

int dfs(int here, vector<int> adj[], int cnt){
	ret = max(ret, cnt);
	
	for(int i : adj[here]){
		if(visited[i]) continue;
		visited[i] = 1;
		dfs(i, adj, cnt + 1);
		visited[i] = 0;
	}
}
int main(){
	cin >> te;
	while(te--){
		tcnt++;
		vector<int> adj[14];
		ret = 1;
		fill(visited, visited + 14, 0);
		
		cin >> n >> m;
		for(int i = 0; i < m; i++){
			cin >> a >> b;
			adj[a].push_back(b);
			adj[b].push_back(a);
		}
		for(int i = 1; i <= n; i++){
			fill(visited, visited + 14, 0);
			visited[i] = 1;
			dfs(i, adj, 1);
		}
		cout << "#" << tcnt << " " << ret << "\n";
	}
}