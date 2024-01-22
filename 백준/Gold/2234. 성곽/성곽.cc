#include<bits/stdc++.h>
using namespace std;
const int dy[] = {0, -1, 0, 1};
const int dx[] = {-1, 0, 1, 0};
int n, m, a[54][54], visited[54][54], comp[2504], ret1, ret2, ret3;

int dfs(int y, int x, int cnt){
	int ret = 1;
	visited[y][x] = cnt;
	
	for(int i = 0; i < 4; i++){
		if(!(a[y][x] & (1 << i))){
			int ny = y + dy[i];
			int nx = x + dx[i];
			if(ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
			if(visited[ny][nx]) continue;
			ret += dfs(ny, nx, cnt);
		}
	}
	return ret;
}
int main(){
	cin >> m >> n;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin >> a[i][j];
		}
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(!visited[i][j]){
				ret1++;
				comp[ret1] = dfs(i, j, ret1);
				ret2 = max(ret2, comp[ret1]);
			}
		}
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(i + 1 < n){
				int a = visited[i][j];
				int b = visited[i + 1][j];
				if(a != b){
					ret3 = max(ret3, comp[a] + comp[b]);
				}
			}
			if(j + 1 < m){
				int a = visited[i][j];
				int b = visited[i][j + 1];
				if(a != b){
					ret3 = max(ret3, comp[a] + comp[b]);
				}
			}
		}
	}
	cout << ret1 << "\n" << ret2 << "\n" << ret3 << "\n";
}