#include<bits/stdc++.h>
using namespace std;
int n, m, dp[54][54], visited[54][54];
char a[54][54];
string s;
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};

int solve(int y, int x, char value){
	if(value == 'H' || y < 0 || y >= n || x < 0 || x >= m) return 0;
	
	if(visited[y][x] == 1){
		cout << "-1\n";
		exit(0);
	}
	int &ret = dp[y][x];
	if(ret != 0) return ret;
	
	visited[y][x] = 1;
	
	for(int i = 0; i < 4; i++){
		int ny = y + (value - '0') * dy[i];
		int nx = x + (value - '0') * dx[i];
		ret = max(ret, solve(ny, nx, a[ny][nx]) + 1);
	}
	visited[y][x] = 0;
	return ret;
}
int main(){
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		cin >> s;
		for(int j = 0; j < m; j++){
			a[i][j] = s[j];
		}
	}
	cout << solve(0, 0, a[0][0]) << "\n";
}