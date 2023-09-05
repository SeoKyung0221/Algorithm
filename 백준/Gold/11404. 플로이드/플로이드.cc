#include<bits/stdc++.h>
using namespace std;
const int INF = 987654321;
int n, m, a, b, c, dist[104][104];

int main(){
	fill(&dist[0][0], &dist[0][0] + 104 * 104, INF);
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		cin >> a >> b >> c;
		dist[a][b] = min(dist[a][b], c);
	}
	for(int i = 1; i <= n; i++){
		dist[i][i] = 0;
	}
	for(int k = 1; k <= n; k++){
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				if(dist[i][j] > dist[i][k] + dist[k][j]){
					dist[i][j] = dist[i][k] + dist[k][j];
				}
			}
		}
	}
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			cout << (dist[i][j] == INF ? 0 : dist[i][j]) << " ";
		}
		cout << "\n";
	}
}