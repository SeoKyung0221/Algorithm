// 그냥 4칸 확인하기
// 이상한 가운데짜리 구현하기

#include<bits/stdc++.h>
using namespace std;
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
int n, m, a[504][504], visited[504][504], ret;

void go(int y, int x, int sum, int cnt){
	if(cnt == 4){
		ret = max(ret, sum);
		return;
	}
	
	for(int i = 0; i < 4; i++){
		int ny = y + dy[i];
		int nx = x + dx[i];
		if(ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
		if(visited[ny][nx]) continue;
		visited[ny][nx] = 1;
		go(ny, nx, sum + a[ny][nx], cnt + 1);
		visited[ny][nx] = 0;
	}
	return;
}

void go2(int y, int x){
	for(int j = 0; j < 4; j++){
		int ans = a[y][x];
		for(int i = 0; i < 4; i++){
			if(i == j) continue;
			int ny = y + dy[i];
			int nx = x + dx[i];
			if(ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
			ans += a[ny][nx];
		}
		ret = max(ret, ans);
	}
	return;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin >> a[i][j];
		}
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			visited[i][j] = 1;
			go(i, j, a[i][j], 1);
			visited[i][j] = 0;
		}
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			go2(i, j);
		}
	}
	cout << ret << "\n";
}