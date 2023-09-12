#include<bits/stdc++.h>
using namespace std;
int n, m, k, a[11][11], b[11][11], x, y, z, ret;
vector<int> tree[11][11];
const int dy[] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int dx[] = {-1, 0, 1, -1, 1, -1, 0, 1};

void SpringSummer(){
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			sort(tree[i][j].begin(), tree[i][j].end());
			vector<int> temp;
			int c = 0;		
			for(int k : tree[i][j]){
				if(k <= b[i][j]){
					temp.push_back(k+1);
					b[i][j] -= k;
				}else{
					c += k / 2;
				}
			}
			tree[i][j] = temp;
			b[i][j] += c;
		}
	}
}
void fall(){
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			for(int k : tree[i][j]){
				if(k % 5 == 0){
					for(int h = 0; h < 8; h++){
						int ny = i + dy[h];
						int nx = j + dx[h];
						if(ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
						tree[ny][nx].push_back(1);
					}
				}
			}
		}
	}
}
void winter(){
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			b[i][j] += a[i][j];
		}
	}
}
int main(){
	fill(&b[0][0], &b[0][0] + 11 * 11, 5);
	cin >> n >> m >> k;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin >> a[i][j];
		}
	}
	for(int i = 0; i < m; i++){
		cin >> x >> y >> z;
		tree[--x][--y].push_back(z);
	}
	for(int i = 0; i < k; i++){
		SpringSummer();
		fall();
		winter();
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			ret += tree[i][j].size();
		}
	}
	cout << ret << "\n";
}