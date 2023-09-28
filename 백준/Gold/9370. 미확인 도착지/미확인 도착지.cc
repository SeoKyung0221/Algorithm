#include<bits/stdc++.h>
using namespace std;
const int INF = 1e9;
int te, n, m, t, s, g, h, a, b, d, x, dist[2004];

int main(){
	cin >> te;
	while(te--){
		fill(dist, dist + 2004, INF);
		vector<pair<int,int>> adj[2004];
		vector<int> v;
		cin >> n >> m >> t;
		cin >> s >> g >> h;
		for(int i = 0; i < m; i++){
            cin >> a >> b >> d;
            d *= 2;
            if(a == g && b == h){
                d--;
            }else if(a == h && b == g)d--;
            adj[a].push_back(make_pair(d, b));
            adj[b].push_back(make_pair(d, a));
        }
		for(int i = 0; i < t; i++){
			cin >> x;
			v.push_back(x);
		}
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
		dist[s] = 0;
		pq.push({0, s});
		while(pq.size()){
			int here = pq.top().second;
			int here_dist = pq.top().first;
			pq.pop();
			if(dist[here] != here_dist) continue;
			for(auto j : adj[here]){
				int next = j.second;
				int next_dist = j.first;
				if(dist[next] > dist[here] + next_dist){
					dist[next] = dist[here] + next_dist;
					pq.push({dist[next], next});
				}
			}
		}
		sort(v.begin(), v.end());
		for(int i : v){
			if(dist[i] % 2 != 0 && dist[i] != INF) cout << i << " ";
		}
		cout << "\n";
	}
}