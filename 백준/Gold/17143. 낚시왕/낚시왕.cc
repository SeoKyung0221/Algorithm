#include<bits/stdc++.h>
using namespace std;
const int dy[] = {-1, 1, 0, 0}; // 00 01 10 11
const int dx[] = {0, 0, 1, -1};
int n, m, k, r, c, s, d, z, cnt = -1, a[104][104], b[104][104], ret;
struct shark{
	int velo, dir, _size;
};
vector<shark> v;

void catchShark(){
	for(int i = 0; i < n; i++){
		if(a[i][cnt] != 0){
			ret += v[a[i][cnt] - 1]._size;
			a[i][cnt] = 0;
			break;
		}
	}
	return;
}

pair<int, int> _move(int y, int x, int k){
	int d = v[k-1].dir, cnt = v[k-1].velo;
	while(cnt--){
		int ny = y + dy[d];
		int nx = x + dx[d];
		if(ny < 0 || ny >= n || nx < 0 || nx >= m){
			d ^= 1;
			ny = y + dy[d];
			nx = x + dx[d];
		}
		y = ny;
		x = nx;
	}
	v[k-1].dir = d;
	return {y, x};
}

void moveShark(){
	memset(b, 0, sizeof(b));
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(a[i][j] != 0){
				int ny, nx;
				tie(ny, nx) = _move(i, j, a[i][j]);
				if(b[ny][nx] != 0){
					if(v[b[ny][nx] - 1]._size < v[a[i][j] - 1]._size) b[ny][nx] = a[i][j];
				}else b[ny][nx] = a[i][j];
				a[i][j] = 0;
			}
		}
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			a[i][j] = b[i][j];
		}
	}
	return;
}
int main(){
	cin >> n >> m >> k;
	for(int i = 1; i <= k; i++){
		cin >> r >> c >> s >> d >> z;
		r--; c--; d--;
		if(d <= 1) s %= (2 * (n - 1));
		else s %= (2 * (m - 1));
		
		a[r][c] = i;
		v.push_back({s, d, z}); 
	}
	while(cnt < m){
		cnt++;
		catchShark();
		moveShark();
	}
	cout << ret << "\n";
	return 0;
}