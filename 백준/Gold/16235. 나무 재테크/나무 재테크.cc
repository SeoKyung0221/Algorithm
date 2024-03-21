#include<bits/stdc++.h>
using namespace std;
int n, m, k, z, y, x, a[11][11], c[11][11], ret;
const int dy[] = {-1, -1, -1, 0, 1, 1, 1, 0};
const int dx[] = {-1, 0, 1, 1, 1, 0, -1, -1};
vector<int> b[11][11];

void springSummer(){
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(b[i][j].size() == 0) continue;
			int temp = 0;
			vector<int> v;
			sort(b[i][j].begin(), b[i][j].end());
			for(int k : b[i][j]){
				if(c[i][j] >= k){
					v.push_back(k + 1);
					c[i][j] -= k;
				}else{
					temp += k / 2;
				}
			}
			c[i][j] += temp;
			b[i][j] = v;
		}
	}
}
void fall(){
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(b[i][j].size() == 0) continue;
			for(int k : b[i][j]){
				if(k % 5 == 0){
					for(int d = 0; d < 8; d++){
						int ny = i + dy[d];
						int nx = j + dx[d];
						if(ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
						b[ny][nx].push_back(1);
					}
				}
			}
		}
	}
}
void winter(){
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			c[i][j] += a[i][j];
		}
	}
}
int main(){
	cin >> n >> m >> k;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin >> a[i][j];
		}
	}
	fill(&c[0][0], &c[0][0] + 11 * 11, 5);
	for(int i = 0; i < m; i++){
		cin >> x >> y >> z;
		x--; y--;
		b[x][y].push_back(z);
	}
	for(int i = 0; i < k; i++){
		springSummer();
		fall();
		winter();
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			ret += b[i][j].size();
		}
	}
	cout << ret << "\n";
	return 0;
}