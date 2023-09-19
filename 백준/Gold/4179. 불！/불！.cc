#include<bits/stdc++.h>
using namespace std;
queue<pair<int, int>> q;
const int INF = 1e9;
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
int r, c, fire_visited[1004][1004], person_visited[1004][1004], ret;
char a[1004][1004];
vector<pair<int,int>> v;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	fill(&fire_visited[0][0], &fire_visited[0][0] + 1004 * 1004, INF);
	cin >> r >> c;
	for(int i = 0; i < r; i++){
		for(int j = 0; j < c; j++){
			cin >> a[i][j];
			if(a[i][j] == 'J'){
				person_visited[i][j] = 1;
				v.push_back({i, j});
			}else if(a[i][j] == 'F'){
				fire_visited[i][j] = 1;
				q.push({i, j});
			}
		}
	}
	while(q.size()){
		int y, x;
		tie(y, x) = q.front();
		q.pop();
		for(int i = 0; i < 4; i++){
			int ny = y + dy[i];
			int nx = x + dx[i];
			if(ny < 0 || ny >= r || nx < 0 || nx >= c || fire_visited[ny][nx] != INF || a[ny][nx] == '#') continue;
			fire_visited[ny][nx] = fire_visited[y][x] + 1;
			q.push({ny,nx});
		}
	}
	q.push({v[0].first, v[0].second});
	while(q.size()){
		int y, x;
		tie(y, x) = q.front();
		if(y == 0 || y == r-1 || x == 0 || x == c-1){
			ret = person_visited[y][x];
			break;
		}
		q.pop();
		for(int i = 0; i < 4; i++){
			int ny = y + dy[i];
			int nx = x + dx[i];
			if(ny < 0 || ny >= r || nx < 0 || nx >= c || person_visited[ny][nx] || a[ny][nx] == '#') continue;
			if(fire_visited[ny][nx] <= person_visited[y][x] + 1) continue;
			person_visited[ny][nx] = person_visited[y][x] + 1;
			q.push({ny, nx});
		}
	}
	if(ret == 0) cout << "IMPOSSIBLE\n";
	else cout << ret << "\n";
}