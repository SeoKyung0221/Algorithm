#include<bits/stdc++.h>
using namespace std;
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
int te, n, a[1004][1004], tag, ret;

int dfs(int y, int x){
	int ret = 1;
	for(int i = 0; i < 4; i++){
		int ny = y + dy[i];
		int nx = x + dx[i];
		if(ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
		if(a[ny][nx] == a[y][x] + 1){
			ret += dfs(ny, nx);
		}
	}
	return ret;
}
int main(){
	cin >> te;
	for(int t = 1; t <= te; t++){
		tag = 0, ret = 0;
		
		cin >> n;
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> a[i][j];
			}
		}
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				int cnt = dfs(i, j);
				if(cnt > ret){
					ret = max(ret, cnt);
					tag = a[i][j];
				}else if(cnt == ret){
					if(tag > a[i][j]) tag = a[i][j];
				}
			}
		}
		
		cout << "#" << t << " " << tag << " " << ret << "\n";
	}
}