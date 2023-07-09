#include<bits/stdc++.h>
using namespace std;
const int INF = 1e9;
int n, m, x, a, b, c, dist[1004], dist2[1004], ret = -1;
vector<pair<int,int>> adj[1004];
priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
int main(){
	fill(dist, dist+1004, INF);
	cin >> n >> m >> x;
	for(int i = 0; i < m; i++){
		cin >> a >> b >> c;
		adj[a].push_back({b,c});
	}
	dist[x] = 0;
	pq.push({x, 0});
	while(pq.size()){
		int here = pq.top().first;
		int here_dist = pq.top().second;
		pq.pop();
		if(dist[here] != here_dist) continue;
		for(auto j : adj[here]){
			int next = j.first;
			int next_dist = j.second;
			if(dist[next] > dist[here] + next_dist){
				dist[next] = dist[here] + next_dist;
				pq.push({next, dist[next]});
			}
		}
	}
	for(int i = 1; i <= n; i++){
		fill(dist2, dist2+1004, INF);
		dist2[i] = 0;
		pq.push({i, 0});
		while(pq.size()){
			int here = pq.top().first;
			int here_dist = pq.top().second;
			pq.pop();
			if(dist2[here] != here_dist) continue;
			for(auto j : adj[here]){
				int next = j.first;
				int next_dist = j.second;
				if(dist2[next] > dist2[here] + next_dist){
					dist2[next] = dist2[here] + next_dist;
					pq.push({next, dist2[next]});
				}
			}
		}
		if(dist[i] != INF || dist2[x] != INF) ret = max(ret, dist[i] + dist2[x]);
	}
	cout << ret << "\n";
}