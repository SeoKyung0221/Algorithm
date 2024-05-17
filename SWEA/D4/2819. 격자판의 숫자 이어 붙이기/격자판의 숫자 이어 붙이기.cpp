#include<bits/stdc++.h>
using namespace std;
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
int te, a[4][4], ret;
map<string, int> mp;

void dfs(int y, int x, int cnt, string temp){
	if(cnt == 6){
		mp[temp] = 1;
		return;
	}
	for(int i = 0; i < 4; i++){
		int ny = y + dy[i];
		int nx = x + dx[i];
		if(ny < 0 || ny >= 4 || nx < 0 || nx >=4) continue;
		dfs(ny, nx, cnt + 1, temp + to_string(a[ny][nx]));
	}
	return;
}
int main(){
	cin >> te;
	for(int t = 1; t <= te; t++){
		ret = 0;
		mp.clear();
		
		for(int i = 0; i < 4; i++){
			for(int j = 0; j < 4; j++){
				cin >> a[i][j];
			}
		}
		
		for(int i = 0; i < 4; i++){
			for(int j = 0; j < 4; j++){
				dfs(i, j, 0, to_string(a[i][j]));
			}
		}
		for(auto it : mp){
			ret++;
		}
		cout << "#" << t << " " << ret << "\n";
	}
}