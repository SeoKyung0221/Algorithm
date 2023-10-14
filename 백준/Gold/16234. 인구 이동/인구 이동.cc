#include<bits/stdc++.h>
using namespace std;
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
int n, l, r, a[54][54], visited[54][54], sum, ret;
vector<pair<int,int>> v;

void dfs(int y, int x){
	for(int i = 0; i < 4; i++){
		int ny = y + dy[i];
		int nx = x + dx[i];
		if(ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
		if(visited[ny][nx]) continue;
		if(abs(a[ny][nx] - a[y][x]) >= l && abs(a[ny][nx] - a[y][x]) <= r){
			visited[ny][nx] = 1;
			v.push_back({ny,nx});
			sum += a[ny][nx];
			dfs(ny, nx);
		}
	}
	return;
}
int main(){
	cin >> n >> l >> r;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin >> a[i][j];
		}
	}
	while(true){
		memset(visited, 0, sizeof(visited));
		bool flag = 0;
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				if(!visited[i][j]){
					v.clear();
					visited[i][j] = 1;
					sum = 0;
					sum += a[i][j];
					v.push_back({i,j});
					dfs(i, j);
					if(v.size() == 1){
						continue;
					}
					for(auto k : v){
						flag = 1;
						a[k.first][k.second] = sum / v.size();
					}
				}
			}
		}
		if(flag == 0) break;
		ret++;
	}
	cout << ret << "\n";
}