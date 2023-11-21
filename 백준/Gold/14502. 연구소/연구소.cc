#include<bits/stdc++.h>
using namespace std;
int a[8][8], visited[8][8], n, m, ret;
vector< pair<int,int> > virus, wall;
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

void dfs(int y, int x){
	for(int i = 0; i < 4; i++){
		int ny = y + dy[i];
		int nx = x + dx[i];
		if(ny < 0 || ny >= n || nx < 0 || nx >= m || visited[ny][nx]) continue;
		if(a[ny][nx] == 1) continue;
		visited[ny][nx] = 1;
		dfs(ny, nx);
	}
}	
int solve(){ // 바이러스 퍼짐. visited로 표현. 
	fill(&visited[0][0], &visited[0][0]+8*8, 0);
	for(pair<int, int> b : virus){
		visited[b.first][b.second] = 1;
		dfs(b.first, b.second);
	}
	int cnt = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(a[i][j] == 0 && !visited[i][j])
				cnt++; // 바이러스가 없는 땅. 
		}
	}
	return cnt;
}
int main(){
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin >> a[i][j];
			if(a[i][j] == 2){
				virus.push_back({i,j});
			}
			if(a[i][j] == 0){
				wall.push_back({i,j});
			}
		}
	}
	for(int i = 0; i < wall.size(); i++){
		for(int j = i+1; j < wall.size(); j++){
			for(int k = j+1; k < wall.size(); k++){
				a[wall[i].first][wall[i].second] = 1;
				a[wall[j].first][wall[j].second] = 1;
				a[wall[k].first][wall[k].second] = 1;
				ret = max(ret, solve());
				a[wall[i].first][wall[i].second] = 0;
				a[wall[j].first][wall[j].second] = 0;
				a[wall[k].first][wall[k].second] = 0;
			}
		}
	}
	cout << ret << "\n";
	return 0;
}