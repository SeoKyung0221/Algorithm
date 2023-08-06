#include<bits/stdc++.h>
using namespace std;
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
const int INF = 1e9;
int n, m, t, d, a[29][29], cost[2600][2600];
string s;
vector<int> v;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	fill(&cost[0][0], &cost[0][0] + 2600 * 2600, INF);
	cin >> n >> m >> t >> d;
	for(int i = 0; i < n; i++){
		cin >> s;
		for(int j = 0; j < m; j++){
			if(s[j] >= 'a' && s[j] <= 'z') a[i][j] = s[j] - 'a' + 26;
			else a[i][j] = s[j] - 'A';
			v.push_back(i * 100 + j);
		}
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			for(int k = 0; k < 4; k++){
				int ny = i + dy[k];
				int nx = j + dx[k];
				if(ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
				int h = abs(a[ny][nx] - a[i][j]);
				if(h <= t){
					if(a[ny][nx] > a[i][j]){
						cost[i * 100 + j][ny * 100 + nx] = h * h;
					}else{
						cost[i * 100 + j][ny * 100 + nx] = 1;
					}
				}
			}
		}
	}
	for(int k : v){
		for(int i : v){
			for(int j : v){
				cost[i][j] = min(cost[i][j], cost[i][k] + cost[k][j]);
			}
		}
	}
	int ret = a[0][0];
	for(int i : v){
		if(cost[0][i] + cost[i][0] <= d) ret = max(ret, a[i / 100][i % 100]);
	}
	cout << ret << "\n";
}