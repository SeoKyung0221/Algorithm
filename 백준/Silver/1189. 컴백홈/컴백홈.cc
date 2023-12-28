#include<bits/stdc++.h>
using namespace std;
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
int n, m, k, visited[6][6], ret;
char a[6][6];

void go(int y, int x){
	if(y == 0 && x == m-1 && visited[y][x] == k){
		ret++;
		return;
	}
	for(int i = 0; i < 4; i++){
		int ny = y + dy[i];
		int nx = x + dx[i];
		if(ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
		if(visited[ny][nx]) continue;
		if(a[ny][nx] == 'T') continue;
		visited[ny][nx] = visited[y][x] + 1;
		go(ny, nx);
		visited[ny][nx] = 0;
	}
}
int main(){
	cin >> n >> m >> k;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin >> a[i][j];
		}
	}
	visited[n-1][0] = 1;
	
	go(n- 1, 0);
	
	cout << ret << "\n";
}