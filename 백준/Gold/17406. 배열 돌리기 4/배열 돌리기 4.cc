#include<bits/stdc++.h>
using namespace std;
const int dy[] = {0, 1, 0, -1};
const int dx[] = {1, 0, -1, 0};
int n, m, k, a[54][54], b[54][54], visited[54][54], r, c, s, sy, sx, ey, ex, dir, ret = 1e9;
struct A{
	int y, x, cnt;
};
vector<A> v;
vector<int> v_idx;
vector<pair<int,int>> vv;

void dfs(int y, int x, int flag){
	if(!flag && y == sy && x == sx) dir = (dir + 1) % 4;
	if(!flag && y == sy && x == ex) dir = (dir + 1) % 4;
	if(!flag && y == ey && x == sx) dir = (dir + 1) % 4;
	if(!flag && y == ey && x == ex) dir = (dir + 1) % 4;
	int ny = y + dy[dir];
	int nx = x + dx[dir];
	if(visited[ny][nx]) return;
	vv.push_back({ny, nx});
	visited[ny][nx] = 1;
	dfs(ny, nx, 0);
}
void rotateAll(int y, int x, int cnt){
	for(int i = cnt; i >= 1; i--){
		vv.clear();
		memset(visited, 0, sizeof(visited));
		sy = y - i;
		sx = x - i;
		ey = y + i;
		ex = x + i;
		dir = 0;
		vv.push_back({sy, sx});
		visited[sy][sx] = 1;
		dfs(sy, sx, 1);
		vector<int> vvv;
		for(auto j : vv){
			vvv.push_back(b[j.first][j.second]);
		}
		rotate(vvv.rbegin(), vvv.rbegin() + 1, vvv.rend());
		for(int j = 0; j < vv.size(); j++){
			b[vv[j].first][vv[j].second] = vvv[j];
		}
	}
}
int solve(){
	for(int i : v_idx){
		rotateAll(v[i].y, v[i].x, v[i].cnt);
	}
	int sum = 1e9;
	for(int i = 0; i < n; i++){
		int cur = 0;
		for(int j = 0; j < m; j++){
			cur += b[i][j];
		}
		sum = min(sum, cur);
	}
	return sum;
}
int main(){
	cin >> n >> m >> k;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin >> a[i][j];
		}
	}
	for(int i = 0; i < k; i++){
		cin >> r >> c >> s; r--; c--;
		v.push_back({r, c, s});
		v_idx.push_back(i);
	}
	do{
		memcpy(b, a, sizeof(a));
		ret = min(ret, solve());
	}while(next_permutation(v_idx.begin(), v_idx.end()));
	cout << ret << "\n";
}