#include<bits/stdc++.h>
using namespace std;
const int INF = 1e9;
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
int t, n, a[129][129], dist[129][129];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> pq;

int main(){
	while(true){
		t++;
		fill(&dist[0][0], &dist[0][0] + 129 * 129, INF);
		cin >> n;
		if(n == 0) break;
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> a[i][j];
			}
		}
		dist[0][0] = a[0][0];
		pq.push({a[0][0], 0});
		while(pq.size()){
			int herey = pq.top().second / 1000;
			int herex = pq.top().second % 1000;
			int here_dist = pq.top().first;
			pq.pop();
			if(dist[herey][herex] != here_dist) continue;
			for(int i = 0; i < 4; i++){
				int ny = herey + dy[i];
				int nx = herex + dx[i];
				if(ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
				if(dist[ny][nx] > dist[herey][herex] + a[ny][nx]){
					dist[ny][nx] = dist[herey][herex] + a[ny][nx];
					pq.push({dist[ny][nx], ny * 1000 + nx});
				}
			}
		}
		cout << "Problem " << t << ": " << dist[n-1][n-1] << "\n"; 
	}
} 