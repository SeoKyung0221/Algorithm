#include<bits/stdc++.h>
using namespace std;
const int INF = 1e9;
int te, n, m, t, s, g, h, a, b, d, x, dist[2004];
priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

int main(){
	cin >> te;
	while(te--){
		vector<pair<int,int>> adj[2004];
		vector<int> v;
		fill(dist, dist + 2004, INF);
		cin >> n >> m >> t >> s >> g >> h;
		for(int i =0; i < m; i++){
			cin >> a >> b >> d;
			d *= 2;
			if((a == g && b == h) || (a == h && b == g)){
				adj[a].push_back({d-1, b});
				adj[b].push_back({d-1, a});
			}else{
				adj[a].push_back({d, b});
				adj[b].push_back({d, a});
			}
		}
		for(int i = 0; i < t; i++){
			cin >> x;
			v.push_back(x);
		}
		dist[s] = 0;
		pq.push({0, s});
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
		sort(v.begin(), v.end());
		for(int i : v){
			if(dist[i] != INF && dist[i] % 2 != 0){
				cout << i << " ";
			}
		}
		cout << "\n";
	}
}