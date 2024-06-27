#include<bits/stdc++.h>
using namespace std;
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
int n, a[29][29], visited[29][29], ret;
vector<int> v;

int dfs(int y, int x){
	int ret = 1;
	
	visited[y][x] = 1;
	
	for(int i = 0; i < 4; i++){
		int ny = y + dy[i];
		int nx = x + dx[i];
		if(ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
		if(visited[ny][nx]) continue;
		if(a[ny][nx] == 0) continue;
		ret += dfs(ny, nx);
	}
	return ret;
}
int main(){
	cin >> n;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			scanf("%1d", &a[i][j]);
		}
	}
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(a[i][j] == 1 && !visited[i][j]){
				ret++;
				int temp = dfs(i, j);
				v.push_back(temp);
			}
		}
	}
	
	cout << ret << "\n";
	
	sort(v.begin(), v.end());
	
	for(int i : v){
		cout << i << "\n";
	}
	
	return 0;
}