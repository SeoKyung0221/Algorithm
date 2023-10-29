#include<bits/stdc++.h>
using namespace std;
const int dy[] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int dx[] = {0, 1, 1, 1, 0, -1, -1, -1};
int te, tcnt, n, visited[24][24], cnt, ret;
char a[24][24];

void dfs(int y, int x){
	for(int i = 0; i < 8; i++){
		int ky = y, kx = x;
		cnt = 1;
		while(true){
			int ny = ky + dy[i];
			int nx = kx + dx[i];
			if(ny < 0 || ny >= n || nx < 0 || nx >= n) break;
			if(a[ny][nx] != 'o') break;
			cnt++;
			ky = ny;
			kx = nx;
		}
		if(cnt >= 5){
			ret = 1;
			break;
		}
	}
}
int main(){
	cin >> te;
	while(te--){
		tcnt++;
		vector<pair<int,int>> v;
		ret = 0;
		
		cin >> n;
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				scanf(" %c", &a[i][j]);
				if(a[i][j] == 'o') v.push_back({i, j});
			}
		}
		for(auto there : v){
			dfs(there.first, there.second);
		}
		if(ret)cout << "#" << tcnt << " " << "YES\n";
		else cout << "#" << tcnt << " " << "NO\n";
	}
}