#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, s, e, m, u, v, p, a[54], dist[54], visited[54];
vector<pair<ll, ll>> adj[54];

int main(){
	cin >> n >> s >> e >> m;
	for(int i = 0; i < m; i++){
		cin >> u >> v >> p;
		adj[u].push_back({p, v});
	}
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	fill(dist, dist + 54, -1e18);
	dist[s] = a[s];
	queue<ll> q;
	
	for(int i = 0; i < n; i++){
		for(int here = 0; here < n; here++){
			for(pair<ll, ll> to : adj[here]){
				ll next = to.second;
				ll next_dist = to.first;
				if(dist[here] != -1e18 && dist[here] + a[next] - next_dist > dist[next]){
					if(i == n - 1) q.push(here);
					dist[next] = dist[here] + a[next] - next_dist;
				}
			}
		}
	}
	int flag = 0;
	while(q.size()){
		ll here = q.front();
		q.pop();
		
		visited[here] = 1;
		
		if(here == e){
			flag = 1;
			break;
		}
		for(pair<ll, ll> to : adj[here]){
			if(visited[to.second]) continue;
			q.push(to.second);
		}
	}
	if(dist[e] == -1e18) cout << "gg\n";
	else if(flag) cout << "Gee\n";
	else cout << dist[e] << "\n";
}