#include<bits/stdc++.h>
using namespace std;
const int dy[] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int dx[] = {-1, 0, 1, -1, 1, -1, 0, 1};
int n, m, k, a[11][11], b[11][11], x, y, z, ret;
vector<int> tree[11][11];

void springSummer(){
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			sort(tree[i][j].begin(), tree[i][j].end());
			vector<int> temp;
			int c = 0;
			for(int k = 0; k < tree[i][j].size(); k++){
				if(tree[i][j][k] <= a[i][j]){
					a[i][j] -= tree[i][j][k];
					temp.push_back(tree[i][j][k] + 1);
				}else{
					c += tree[i][j][k] / 2;
				}
			}
			tree[i][j] = temp;
			a[i][j] += c;
		}
	}
}
void fall(){
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			for(int t: tree[i][j]){
				if(t % 5 == 0){
					for(int k = 0; k < 8; k++){
						int ny = i + dy[k];
						int nx = j + dx[k];
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
			a[i][j] += b[i][j];
		}
	}
}
int main(){
	fill(&a[0][0], &a[0][0] + 11 * 11, 5);
	cin >> n >> m >> k;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin >> b[i][j];
		}
	}
	for(int i = 0; i < m; i++){
		cin >> x >> y >> z;
		tree[--x][--y].push_back(z);
	}
	for(int i = 0; i < k; i++){
		springSummer();
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