#include<bits/stdc++.h>
using namespace std;
int n, m, h[10004], visited[10004], a, b, mx;
vector<int> adj[10004];

int dfs(int here){
	int ret = 1;
	visited[here] = 1;
	for(auto it : adj[here]){
		if(visited[it]) continue;
			ret += dfs(it);
	}
	return ret;
}

int main(){
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		cin >> a >> b;
		adj[b].push_back(a);
	}
	for(int i = 1; i <= n; i++){
		fill(&visited[0], &visited[0]+10004, 0);
		h[i] = dfs(i);
		mx = max(mx, h[i]);	
	}
	for(int i = 1; i <= n; i++){
		if(h[i] == mx)
			cout << i << " ";
	}
	return 0;
}

