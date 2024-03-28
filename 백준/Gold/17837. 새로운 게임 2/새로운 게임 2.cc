#include<bits/stdc++.h>
using namespace std;
const int dy[] = {0, 0, -1, 1};
const int dx[] = {1, -1, 0, 0};
int n, k, a[14][14], p, q, w, ret;
struct Chess{
	int y, x, dir;
};
vector<int> v[14][14];
vector<Chess> vv;

bool check(){
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(v[i][j].size() >= 4) return true;
		}
	}
	return false;
}
void move(int y, int x, int dir, int idx){
	int ny = y + dy[dir];
	int nx = x + dx[dir];
	if(ny < 0 || ny >= n || nx < 0 || nx >= n || a[ny][nx] == 2){ // 파랑 
		vv[idx].dir = dir ^ 1;
		ny = y + dy[vv[idx].dir];
		nx = x + dx[vv[idx].dir];
		if(ny < 0 || ny >= n || nx < 0 || nx >= n || a[ny][nx] == 2) return;
	}
	
	auto pos = find(v[y][x].begin(), v[y][x].end(), idx);
	
	vector<int> &here_v = v[y][x];
	vector<int> &next_v = v[ny][nx];
	
	if(a[ny][nx] == 1) reverse(pos, here_v.end());
	for(auto it = pos; it != here_v.end(); it++){
		next_v.push_back((*it));
		vv[*it].y = ny;
		vv[*it].x = nx;
	}
	here_v.erase(pos, here_v.end());
	return;
}
bool solve(){
	for(int i = 0; i < k; i++){
		move(vv[i].y, vv[i].x, vv[i].dir, i);
		if(check()) return 1;
	}
	return 0;
}
int main(){
	cin >> n >> k;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin >> a[i][j];
		}
	}
	for(int i = 0; i < k; i++){
		cin >> p >> q >> w;
		p--; q--; w--;
		v[p][q].push_back(i);
		vv.push_back({p, q, w});
	}
	int flag = 0;
	while(ret <= 1000){
		ret++;
		if(solve()){
			flag = 1;
			break;
		}
	}
	if(flag) cout << ret << "\n";
	else cout << -1 << "\n";
}