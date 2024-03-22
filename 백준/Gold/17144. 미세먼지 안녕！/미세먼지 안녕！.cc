#include<bits/stdc++.h>
using namespace std;
const int dy_left[] = {0, -1, 0, 1};
const int dx_left[] = {1, 0, -1, 0};
const int dy_right[] = {0, 1, 0, -1};
const int dx_right[] = {1, 0, -1, 0};
int n, m, t, a[54][54], b[54][54], sy1, sx1, sy2, sx2, ret;

void spread(){
	memset(b, 0, sizeof(b));
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(a[i][j] == -1) continue;
			int k = a[i][j] / 5;
			for(int h = 0; h < 4; h++){
				int ny = i + dy_left[h];
				int nx = j + dx_left[h];
				if(ny < 0 || ny >= n || nx < 0 || nx >= m || a[ny][nx] == -1) continue;
				b[ny][nx] += k;
				a[i][j] -= k;
			}
		}
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			a[i][j] += b[i][j];
		}
	}
	return;
}
void clean(int y, int x, int flag){
	vector<pair<int, int>> v;
	if(flag == 0){
		int dir = 0;
		while(true){
			int ny = y + dy_left[dir];
			int nx = x + dx_left[dir];
			if(ny == sy1 && nx == sx1) break;
			if(ny < 0 || ny >= n || nx < 0 || nx >= m){
				dir++;
				ny = y + dy_left[dir];
				nx = x + dx_left[dir];
			}
			if(ny == sy1 && nx == sx1) break;
			v.push_back({ny, nx});
			y = ny;
			x = nx;
		}
	}else{
		int dir = 0;
		while(true){
			int ny = y + dy_right[dir];
			int nx = x + dx_right[dir];
			if(ny == sy2 && nx == sx2) break;
			if(ny < 0 || ny >= n || nx < 0 || nx >= m){
				dir++;
				ny = y + dy_right[dir];
				nx = x + dx_right[dir];
			}
			if(ny == sy2 && nx == sx2) break;
			v.push_back({ny, nx});
			y = ny;
			x = nx;
		}
	}
	for(int i = v.size() - 1; i > 0; i--){
		a[v[i].first][v[i].second] = a[v[i - 1].first][v[i - 1].second];
	}
	a[v[0].first][v[0].second] = 0;
	return;
}
int main(){
	int flag = 0;
	cin >> n >> m >> t;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin >> a[i][j];
			if(a[i][j] == -1){
				if(flag == 0){
					sy1 = i; sx1 = j;
					flag = 1;
				}else{
					sy2 = i; sx2 = j;
				}
			}
		}
	}
	
	while(t--){
		spread();
		clean(sy1, sx1, 0);
		clean(sy2, sx2, 1);	
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(a[i][j] == -1) continue;
			ret += a[i][j];
		}
	}
	cout << ret << "\n";
}