#include<bits/stdc++.h>
using namespace std;
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
int n, m, a[1004][1004], visited[1004][1004], ret;
queue<pair<int, int>> q;

bool check(){
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(a[i][j] == -1) continue;
			if(a[i][j] == 0) return false;
		}
	}
	return true;
}
int main(){
	cin >> m >> n;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin >> a[i][j];
			if(a[i][j] == 1){
				q.push({i, j});
				visited[i][j] = 1;
			}
		}
	}
	while(q.size()){
		if(check()) break;
		ret++;
		int qSize = q.size();
		for(int j = 0; j < qSize; j++){
			int y, x;
			tie(y, x) = q.front();
			q.pop();
			for(int i = 0; i < 4; i++){
				int ny = y + dy[i];
				int nx = x + dx[i];
				if(ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
				if(visited[ny][nx]) continue;
				if(a[ny][nx] == -1) continue;
				visited[ny][nx] = 1;
				a[ny][nx] = 1;
				q.push({ny, nx});
			}
		}
	}
	if(check()) cout << ret << "\n";
	else cout << "-1\n";
}