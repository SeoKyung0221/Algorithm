#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
int n, s, e, m, a, b, pay, visited[54];
ll dist[54], cost[54];
vector<pair<int,int>> adj[54];
int main(){
	fill(dist, dist+54, -INF);
	cin >> n >> s >> e >> m;
	for(int i = 0; i < m; i++){
		cin >> a >> b >> pay;
		adj[a].push_back({b,pay});
	}
	for(int i = 0; i < n; i++){
		cin >> cost[i];
	}
	dist[s] = cost[s]; queue<int> q;
	for(int i = 0; i < n; i++){
		for(int here = 0; here < n; here++){
			for(auto it : adj[here]){
				int next = it.first;
				int next_dist = it.second;
				if(dist[here] != -INF && dist[next] < dist[here] + cost[next] - next_dist){
					if(i == n-1) q.push(here);
					dist[next] = dist[here] + cost[next] - next_dist;
				}
			}
		}
	}
	int flag = 0;
	while(q.size()){
		int here = q.front(); q.pop();
		for(auto it : adj[here]){
			int next = it.first;
			if(visited[next] == 1) continue;
			if(next == e){
				flag = 1;
				break;
			}
			visited[next] = 1;
			q.push(next);
		}
		if(flag) break;
	}
	if(dist[e] == -INF) cout << "gg" << "\n";
	else if(flag == 1) cout << "Gee" << "\n";
	else cout << dist[e] << "\n";
	return 0;
}