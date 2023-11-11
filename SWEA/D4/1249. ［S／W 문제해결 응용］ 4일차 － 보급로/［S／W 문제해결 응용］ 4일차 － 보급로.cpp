#include<bits/stdc++.h>
using namespace std;
const int INF = 1e9;
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
int te, tcnt, n, a[104][104], dist[104][104];

int main(){
	cin >> te;
	while(te--){
		tcnt++;
		fill(&dist[0][0], &dist[0][0] + 104 * 104, INF);
		fill(&a[0][0], &a[0][0] + 104 * 104, 0);
		cin >> n;
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				scanf("%1d", &a[i][j]);
			}
		}
		priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
		dist[0][0] = a[0][0];
		pq.push({0, 0});
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
					pq.push({dist[ny][nx], 1000 * ny + nx});
				}
			}
		}
		cout << "#" << tcnt << " " << dist[n-1][n-1] << "\n";
	}
}