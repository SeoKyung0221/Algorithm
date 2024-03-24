#include<bits/stdc++.h>
using namespace std;
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
int n, m, k, r, c, s, d, z, a[104][104], b[104][104], cnt, ret;
vector<tuple<int, int, int>> v; // 속도, 방향, 크기.

void catchFish(int cnt){
	for(int i = 1; i <= n; i++){
		if(a[i][cnt] != 0){
			ret += get<2> (v[a[i][cnt] - 1]);
			a[i][cnt] = 0;
			break;
		}
	}
	return;
}

pair<int, int> _move(int y, int x, int k){
	int velo, dir, size;
	tie(velo, dir, size) = v[k - 1];	
	
	while(velo--){
		int ny = y + dy[dir];
		int nx = x + dx[dir];
		if(ny <= 0 || ny > n || nx <= 0 || nx > m){
			dir = (dir + 2) % 4;
			ny = y + dy[dir];
			nx = x + dx[dir];
		}
		y = ny;
		x = nx;
	}
	get<1>(v[k - 1]) = dir;
	
	return {y, x};
}
void moveFish(){
	memset(b, 0, sizeof(b));
	
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			if(a[i][j] != 0){
				int ny, nx;
				tie(ny, nx) = _move(i, j, a[i][j]);
				if(b[ny][nx] != 0){
					if(get<2>(v[b[ny][nx] - 1]) < get<2>(v[a[i][j] - 1])) b[ny][nx] = a[i][j];
				}else b[ny][nx] = a[i][j];
				a[i][j] = 0;
			}
		}
	}
	
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			a[i][j] = b[i][j];
		}
	}
	
	return;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m >> k;
	for(int i = 1; i <= k; i++){
		cin >> r >> c >> s >> d >> z;
		if(d == 1 || d == 2) s %= 2 * (n - 1);
		else if(d == 3 || d == 4) s %= 2 * (m - 1);
		if(d == 1) d = 0;
		else if(d == 2) d = 2;
		else if(d == 3) d = 1;
		else if(d == 4) d = 3;
		a[r][c] = i;
		v.push_back(make_tuple(s, d, z)); 
	}

	while(cnt < m + 1){
		cnt++;
		catchFish(cnt);
		moveFish();
	}
	cout << ret << "\n";
}