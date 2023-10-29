#include<bits/stdc++.h>
using namespace std;
int t, m, n, k, a[54][54], visited[54][54], X, Y;
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

void dfs(int y, int x){
	visited[y][x] = 1;
	for(int i = 0; i < 4; i++){
		int ny = y + dy[i];
		int nx = x + dx[i];
		if(ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
		if(a[ny][nx] && visited[ny][nx] == 0)
			dfs(ny, nx);	
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> t;
	for(int i = 0; i < t; i++){
		fill(&a[0][0], &a[0][0] + 54 * 54, 0);
		fill(&visited[0][0], &visited[0][0] + 54 * 54, 0);
		int ret = 0;
		cin >> m >> n >> k;
		for(int i = 0; i < k; i++){
			cin >> X >> Y;
			a[Y][X] = 1;
		}
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				if(a[i][j] && visited[i][j]==0){
				dfs(i, j);
				ret++;
				}
			}
		}
		cout << ret << "\n";
	}
	return 0;
}