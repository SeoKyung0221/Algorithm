#include<bits/stdc++.h>
using namespace std;
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
int n, m, ret, visited[54][54], flag, dp[54][54];
char a[54][54];

int go(int y, int x){
	if(y < 0 || y >= n || x < 0 || x >= m || a[y][x] == 'H'){
		return 0;
	}
	if(visited[y][x]){
		cout << -1 << "\n";
		exit(0);
	}
	int &ret = dp[y][x];
	if(ret != -1) return ret;
	
	ret = 0;
	
	visited[y][x] = 1;
	int cnt = a[y][x] - '0';
	for(int i = 0; i < 4; i++){
		int ny = y + dy[i] * cnt;
		int nx = x + dx[i] * cnt;
		ret = max(ret, go(ny, nx) + 1);
	}
	visited[y][x] = 0;
	return ret;
}
int main(){
	memset(dp, -1, sizeof(dp));
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin >> a[i][j];
		}
	}
	cout << go(0, 0) << "\n";
}