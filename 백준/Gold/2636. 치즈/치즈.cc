#include<bits/stdc++.h>
using namespace std;
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
int n, m, a[104][104], visited[104][104], ret, prev_ret;

void bfs(){
	memset(visited, 0, sizeof(visited));
	queue<pair<int, int>> q;
	q.push({0, 0});
	visited[0][0] = 1;
	
	while(q.size()){
		int y, x;
		tie(y, x) = q.front();
		q.pop();
		for(int i = 0; i < 4; i++){
			int ny = y + dy[i];
			int nx = x + dx[i];
			if(ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
			if(visited[ny][nx] == 1) continue;
			if(a[ny][nx] == 0){
				visited[ny][nx] = 1;
				q.push({ny, nx});
			}else if(a[ny][nx] == 1){
				visited[ny][nx] = 1;
				a[ny][nx] = 0;
			}
		}
	}
	return;
}
bool check(){
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(a[i][j] == 1) return false;
		}
	}
	return true;
}
int cheeze(){
	int ret = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(a[i][j] == 1) ret++;
		}
	}
	return ret;
}
int main(){
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin >> a[i][j];
			if(a[i][j] == 1) prev_ret += 1;
		}
	}
	while(true){
		ret++;
		bfs();
		if(check()) break;
		prev_ret = cheeze();
	}
	cout << ret << "\n" << prev_ret << "\n";
}