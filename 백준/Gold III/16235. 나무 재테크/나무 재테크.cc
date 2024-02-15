#include<bits/stdc++.h>
using namespace std;
int n, m, k, a[14][14], c[14][14], x, y, z, ret;
vector<int> b[14][14];
const int dy[] = {-1, -1, -1, 0, 1, 1, 1, 0};
const int dx[] = {-1, 0, 1, 1, 1, 0, -1, -1};

void springSummer(){
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(b[i][j].size() == 0) continue;
			vector<int> v;
			int temp = 0;
			sort(b[i][j].begin(), b[i][j].end());
			for(int h : b[i][j]){
				if(c[i][j] >= h){
					c[i][j] -= h;
					v.push_back(h + 1);
				}else{
					temp += h / 2;
				}
			}
			b[i][j] = v;
			c[i][j] += temp;
		}
	}
}
void fall(){
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(b[i][j].size() == 0) continue;
			for(int p : b[i][j]){
				if(p % 5 == 0){
					for(int h = 0; h < 8; h++){
						int ny = i + dy[h];
						int nx = j + dx[h];
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
	fill(&c[0][0], &c[0][0] + 14 * 14, 5);
	cin >> n >> m >> k;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin >> a[i][j];
		}
	}
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
			if(b[i][j].size() == 0) continue;
			ret += b[i][j].size();
		}
	}
	cout << ret << "\n";
}