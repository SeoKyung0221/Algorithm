#include<bits/stdc++.h>
using namespace std;
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
int n, m, dir, y, x, a[54][54], ret;

int main(){
	cin >> n >> m >> y >> x >> dir;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin >> a[i][j]; 
		}
	}
	while(true){
		if(a[y][x] == 0){
			ret++;
			a[y][x] = 2;
		}
		int flag = 0;
		for(int i = 0; i < 4; i++){
			int ny = y + dy[i];
			int nx = x + dx[i];
			if(ny < 0 || ny >= n || nx < 0 || nx >= m || a[ny][nx] == 1) continue;
			if(a[ny][nx] == 0) flag = 1;
		}
		if(flag == 0){
			int ny = y - dy[dir];
			int nx = x - dx[dir];
			if(ny < 0 || ny >= n || nx < 0 || nx >= m || a[ny][nx] == 1) break;
			y = ny;
			x = nx;
		}else{
			while(true){
				dir = (dir + 3) % 4;
				int ny = y + dy[dir];
				int nx = x + dx[dir];
				if(ny < 0 || ny >= n || nx < 0 || nx >= m || a[ny][nx] == 1) continue;
				if(a[ny][nx] == 0){
					y = ny;
					x = nx;
					break;
				}
			}
		}
	}
	cout << ret << "\n";
}