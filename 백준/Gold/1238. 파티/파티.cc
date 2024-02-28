#include<bits/stdc++.h>
using namespace std;
int n, m, x, a, b, t, dist[1004], dist_[1004], ret;
vector<pair<int, int>> adj[1004];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n >> m >> x;
	for(int i = 0; i < m; i++){
		cin >> a >> b >> t;
		adj[a].push_back({t, b});
	}
	
	fill(dist_, dist_ + 1004, 1e9);
	dist_[x] = 0;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({0, x});
	while(pq.size()){
		int here = pq.top().second;
		int here_dist = pq.top().first;
		pq.pop();
		if(dist_[here] != here_dist) continue;
		for(auto to : adj[here]){
			int next = to.second;
			int next_dist = to.first;
			if(dist_[next] > dist_[here] + next_dist){
				dist_[next] = dist_[here] + next_dist;
				pq.push({dist_[next], next});
			}
		}
	}
	
	for(int i = 1; i <= n; i++){
		fill(dist, dist + 1004, 1e9);
		dist[i] = 0;
		pq.push({0, i});
		while(pq.size()){
			int here = pq.top().second;
			int here_dist = pq.top().first;
			pq.pop();
			if(dist[here] != here_dist) continue;
			for(auto to : adj[here]){
				int next = to.second;
				int next_dist = to.first;
				if(dist[next] > dist[here] + next_dist){
					dist[next] = dist[here] + next_dist;
					pq.push({dist[next], next});
				}
			}
		}
		ret = max(ret, dist[x] + dist_[i]);
	}
	cout << ret << "\n";
}
