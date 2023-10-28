#include<bits/stdc++.h>
using namespace std;
const int dy[] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int dx[] = {0, 1, 1, 1, 0, -1, -1, -1};
int te, tcnt, n, m, a[9][9], p, q, flag;

void solve(int y, int x, int cnt){
	vector<pair<int,int>> v;
	for(int i = 0; i < 8; i++){
		v.clear();
		v.push_back({y, x});
		int ky = y, kx = x;
		while(true){
			int ny = ky + dy[i];
			int nx = kx + dx[i];
			if(ny < 0 || ny >= n || nx < 0 || nx >= n || a[ny][nx] == 0) break;
			if(a[ny][nx] == cnt){
				for(auto i : v){
					a[i.first][i.second] = cnt;
				}
				break;
			}
			if(a[ny][nx] != cnt){
				v.push_back({ny, nx});
				ky = ny;
				kx = nx;
			}
		}
	}
}
pair<int, int> solve2(){
	int black = 0, white = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(a[i][j] == 1) black++;
			else if(a[i][j] == 2) white++;
		}
	}
	return make_pair(black, white);
}
int main(){
	cin >> te;
	while(te--){
		tcnt++;
		pair<int, int> ret;
		memset(a, 0, sizeof(a));
		
		cin >> n >> m;
		int k = n / 2;
		a[k][k] = 2; a[k-1][k-1] = 2; a[k-1][k] = 1; a[k][k-1] = 1;
		
		for(int i = 0; i < m; i++){
			cin >> p >> q >> flag; p--; q--;
			solve(q, p, flag);
		}
		ret = solve2();
		cout << "#" << tcnt << " " << ret.first << " " << ret.second << "\n";
	}
}