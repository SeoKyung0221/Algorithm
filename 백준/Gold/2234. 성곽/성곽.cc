#include<bits/stdc++.h>
using namespace std;
const int dy[] = {0, -1, 0, 1};
const int dx[] = {-1, 0, 1, 0};
int n, m, a[54][54], visited[54][54], cnt, ret2, ret3, combSize[2504];

int dfs(int y, int x, int cnt){
	int ret = 1;
	visited[y][x] = cnt;
	for(int i = 0; i < 4; i++){
		if(!(a[y][x] & (1 << i))){
			int ny = y + dy[i];
			int nx = x + dx[i];
			if(ny < 0 || ny >= m || nx < 0 || nx >= n) continue;
			if(visited[ny][nx]) continue;
			ret += dfs(ny, nx, cnt);
		}
	}
	return ret;
}
int main(){
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		for(int j = 0; j < n; j++){
			cin >> a[i][j];
		}
	}
	for(int i = 0; i < m; i++){
		for(int j = 0; j < n; j++){
			if(!visited[i][j]){
				cnt++;
				combSize[cnt] = dfs(i, j, cnt);
				ret2 = max(ret2, combSize[cnt]);
			}
		}
	}
	for(int i = 0; i < m; i++){
		for(int j = 0; j < n; j++){
			if(i + 1 < m){
				int b= visited[i][j];
				int c= visited[i+1][j];
				if(b != c){
					ret3 = max(ret3, combSize[b] + combSize[c]);
				}
			}
			if(j + 1 < n){
				int b = visited[i][j];
				int c = visited[i][j+1];
				if(b != c){
					ret3 = max(ret3, combSize[b] + combSize[c]);
				}
			}
		}
	}
	cout << cnt << "\n" << ret2 << "\n" << ret3 << "\n";
}