#include<bits/stdc++.h>
using namespace std;
#define y1 aaaa
const int dy[] = {1, 0, -1, 0};
const int dx[] = {0, 1, 0, -1};
int m, n, k, a[104][104], x1, y1, x2, y2, ret;
vector<int> v;

int dfs(int y, int x){
	int ret = 1;
	a[y][x] = 1;
	for(int i = 0; i < 4; i++){
		int ny = y + dy[i];
		int nx = x + dx[i];
		if(ny < 0 || ny >= m || nx < 0 || nx >= n) continue;
		if(a[ny][nx]) continue;
		ret += dfs(ny, nx);
	}
	return ret;
}
int main(){
	cin >> m >> n >> k;
	for(int i = 0; i < k; i++){
		cin >> x1 >> y1 >> x2 >> y2;
		for(int p = y1; p < y2; p++){
			for(int q = x1; q < x2; q++){
				a[p][q] = 1;
			}
		}
	}
	for(int i = 0; i < m; i++){
		for(int j = 0; j < n; j++){
			if(!a[i][j]){
				ret++;
				v.push_back(dfs(i, j));
			}
		}
	}
	sort(v.begin(), v.end());
	
	cout << ret << "\n";
	for(int i : v){
		cout << i << " ";
	}
}