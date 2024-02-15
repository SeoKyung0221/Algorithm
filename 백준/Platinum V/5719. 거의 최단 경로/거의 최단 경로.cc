#include<bits/stdc++.h>
using namespace std;
int n, m, s, d, dist[504], u, v, p, a[504][504];

void dijkstra(){
	fill(dist, dist + 504, 1e9);
	dist[s] = 0;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({0, s});
	while(pq.size()){
		int here = pq.top().second;
		int here_dist = pq.top().first;
		pq.pop();
		if(dist[here] != here_dist) continue;
		for(int i = 0; i < n; i++){
			if(a[here][i] == -1) continue;
			int next_dist = a[here][i];
			if(dist[i] > dist[here] + a[here][i]){
				dist[i] = dist[here] + a[here][i];
				pq.push({dist[i], i});
			}
		}
	}
}

void erase(){
	queue<int> q;
	q.push(d);
	while(q.size()){
		int here = q.front();
		q.pop();
		for(int i = 0; i < n; i++){
			if(dist[here] == dist[i] + a[i][here] && a[i][here] != -1){
				a[i][here] = -1;
				q.push(i);
			}
		}
	}
}
int main(){
	while(true){
		memset(a, -1, sizeof(a));
		
		cin >> n >> m;
		if(n == 0 && m == 0) break;
		cin >> s >> d;
		
		for(int i = 0; i < m; i++){
			cin >> u >> v >> p;
			a[u][v] = p;
		}
		
		dijkstra();
		erase();
		dijkstra();
		
		cout << ((dist[d] == 1e9) ? -1 : dist[d]) << "\n";
	}
	return 0;
}