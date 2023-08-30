#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e9;
ll n, m, a, b, c, dist[504];
vector<pair<ll, ll>> adj[504];
int main(){
	fill(dist, dist + 504, INF);
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		cin >> a >> b >> c;
		adj[a-1].push_back({b-1, c});
	}
	dist[0] = 0;
	queue<ll> q;
	for(int i = 0; i < n; i++){
		for(int here = 0; here < n; here++){
			for(auto j : adj[here]){
				ll next = j.first;
				ll next_dist = j.second;
				if(dist[here] != INF && dist[next] > dist[here] + next_dist){
					if(i == n-1) q.push(next);
					dist[next] = dist[here] + next_dist;
				}
			}
		}
	}
	if(q.size()) cout << -1 << "\n";
    else for(int i = 1; i < n; i++) cout << (dist[i] == INF ? -1 : dist[i]) << "\n";
	return 0;
}