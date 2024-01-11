#include<bits/stdc++.h>
using namespace std;
int n, m, dist[104][104], a, b, c;

int main(){
	cin >> n >> m;
	
	fill(&dist[0][0], &dist[0][0] + 104 * 104, 1e9);
	
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
			if(dist[i][j] == 1e9){
				cout << 0 << " ";
			}else cout << dist[i][j] << " ";
		}
		cout << "\n";
	}
}