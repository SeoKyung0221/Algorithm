#include<bits/stdc++.h>
using namespace std;
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
int n, m, a[104][104], visited[104][104];
vector<pair<int, int>> v;

void go(int y, int x){
	visited[y][x] = 1;
	
	if(a[y][x] == 1){
		v.push_back({y, x});
		return;
	}
	for(int i = 0; i < 4; i++){
		int ny = y + dy[i];
		int nx = x + dx[i];
		if(ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
		if(visited[ny][nx]) continue;
		go(ny, nx);
	}
}
int main(){
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin >> a[i][j];
		}
	}
	int cnt1 = 0;
	int cnt2 = 0;
	while(true){
		v.clear();
		cnt1++;
		memset(visited, 0, sizeof(visited));
		int cnt3 = 0;
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				if(a[i][j] == 1) cnt3++;
			}
		}
		go(0, 0);
		for(pair<int, int> i : v){
			a[i.first][i.second] = 0;
		}
		int flag = 1;
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				if(a[i][j] == 1){
					flag = 0;
					break;
				}
			}
		}
		if(flag){
			cnt2 = cnt3;
			break;
		}
	}
	cout << cnt1 << "\n" << cnt2 << "\n";
}