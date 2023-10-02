#include<bits/stdc++.h>
using namespace std;
const int INF = 1e9;
int V, E, k, u, v, w, dist[20004];
vector<pair<int,int>> adj[20004];
priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

int main(){
	fill(dist, dist + 20004, INF);
	cin >> V >> E >> k;
	for(int i = 0; i < E; i++){
		cin >> u >> v >> w;
		adj[u].push_back({w, v});
	}
	dist[k] = 0;
	pq.push({0, k});
	while(pq.size()){
		int here = pq.top().second;
		int here_dist = pq.top().first;
		pq.pop();
		if(dist[here] != here_dist) continue;
		for(auto i : adj[here]){
			int next = i.second;
			int next_dist = i.first;
			if(dist[next] > dist[here] + next_dist){
				dist[next] = dist[here] + next_dist;
				pq.push({dist[next], next});
			}
		}
	}
	for(int i = 1; i <= V; i++){
		if(dist[i] == INF){
			cout << "INF" << "\n";
		}else{
			cout << dist[i] << "\n";
		}
	}
}