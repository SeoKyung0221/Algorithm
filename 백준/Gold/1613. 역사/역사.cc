#include<bits/stdc++.h>
using namespace std;
int n, k, a, b, dist[404][404], s;

int main(){
	ios_base::sync_with_stdio(false);
	cout.tie(NULL); cin.tie(NULL);
	fill(&dist[0][0], &dist[0][0] + 404 * 404, 1e9);
	cin >> n >> k;
	for(int i = 0; i < k; i++){
		cin >> a >> b;
		dist[a][b] = min(dist[a][b], 1);
	}
	
	for(int k = 1; k <= n; k++){
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				if(dist[i][j] > dist[i][k] + dist[k][j]) dist[i][j] = dist[i][k] + dist[k][j];
			}
		}
	}
	
	cin >> s;
	for(int i = 0; i < s; i++){
		cin >> a >> b;
		int p = dist[a][b], q= dist[b][a];
		if(p == 1e9 && q == 1e9) cout << "0\n";
		else if(q == 1e9) cout << "-1\n";
		else cout << "1\n";
	}
}