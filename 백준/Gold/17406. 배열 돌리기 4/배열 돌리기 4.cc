#include<bits/stdc++.h>
using namespace std;
const int dy[] = {0, 1, 0, -1};
const int dx[] = {1, 0, -1, 0};
int n, m, k, a[54][54], visited[54][54], b[54][54], r, c, s, sy, sx, ey, ex, dir, ret = 1e9;
struct A{
	int y, x, cnt;
};
vector<A> v;
vector<int> v_idx;
vector<pair<int, int>> vv;
void go(int y, int x, int first){
	if(!first && y == sy && x == sx) dir++;
	if(!first && y == sy && x == ex) dir++;
	if(!first && y == ey && x == ex) dir++;
	if(!first && y == ey && x == sx) dir++;
	int ny = y + dy[dir];
	int nx = x + dx[dir];
	if(visited[ny][nx]) return;
	vv.push_back({ny, nx});
	visited[ny][nx] = 1;
	go(ny, nx, 0);
}
void rotateAll(int y, int x, int cnt){
	memset(visited, 0, sizeof(visited));
	for(int s = 1; s <= cnt; s++){
		vv.clear();
		sy = y - s;
		sx = x - s;
		ey = y + s;
		ex = x + s;
		dir = 0;
		visited[sy][sx] = 1;
		vv.push_back({sy, sx});
		go(sy, sx, 1);
		vector<int> vvv;
		for(auto i : vv){
			vvv.push_back(b[i.first][i.second]);
		}
		rotate(vvv.rbegin(), vvv.rbegin() + 1, vvv.rend());
		for(int i = 0; i < vv.size(); i++){
			b[vv[i].first][vv[i].second] = vvv[i];
		}
	}
}
int solve(){
	for(int i : v_idx){
		rotateAll(v[i].y, v[i].x, v[i].cnt);
	}
	int ans = 1e9;
	for(int i = 0; i < n; i++){
		int sum = 0;
		for(int j = 0; j < m; j++){
			sum += b[i][j];
		}
		ans = min(ans, sum);
	}
	return ans;
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