#include<bits/stdc++.h>
using namespace std;
const int INF = 1e9;
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
int n, m, sy, sx, fire_visited[1004][1004], person_visited[1004][1004], ret;
char a[1004][1004];

int main(){
	fill(&fire_visited[0][0], &fire_visited[0][0] + 1004 * 1004, INF);
	queue<pair<int, int>> q;
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin >> a[i][j];
			if(a[i][j] == 'J'){
				sy = i;
				sx = j;
				person_visited[sy][sx] = 1;
			}else if(a[i][j] == 'F'){
				fire_visited[i][j] = 1;
				q.push({i,j});
			}
		}
	}
	while(q.size()){
		int y, x;
		tie(y, x) = q.front(); q.pop();
		for(int i = 0; i < 4; i++){
			int ny = y + dy[i];
			int nx = x + dx[i];
			if(ny < 0 || ny >= n || nx < 0 || nx >= m || fire_visited[ny][nx] != INF || a[ny][nx] == '#') continue;
			fire_visited[ny][nx] = fire_visited[y][x] + 1;
			q.push({ny,nx});
		}
	}
	q.push({sy, sx});
	while(q.size()){
		int y, x;
		tie(y, x) = q.front(); q.pop();
		if(y == 0 || y == n-1 || x == 0 || x == m-1){
			ret = person_visited[y][x];
			break;
		}
		for(int i = 0; i < 4; i++){
			int ny = y + dy[i];
			int nx = x + dx[i];
			if(ny < 0 || ny >= n || nx < 0 || nx >= m || person_visited[ny][nx] || a[ny][nx] == '#') continue;
			if(fire_visited[ny][nx] <= person_visited[y][x] + 1) continue;
			person_visited[ny][nx] = person_visited[y][x] + 1;
			q.push({ny,nx});
		}
	}
	if(ret != 0){
		cout << ret << "\n";
	}else{
		cout << "IMPOSSIBLE\n";
	}
	return 0;
}