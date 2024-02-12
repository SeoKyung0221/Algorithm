#include<bits/stdc++.h>
using namespace std;
int n, m, t, d, a[26][26], b[3000][3000], ret;
string s;
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
vector<int> v;

int main(){
	cin >> n >> m >> t >> d;
	for(int i = 0; i < n; i++){
		cin >> s;
		for(int j = 0; j < m; j++){
			if(s[j] >= 'A' && s[j] <= 'Z'){
				a[i][j] = s[j] - 'A';
			}else{
				a[i][j] = s[j] - 'a' + 26;
			}
		}
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			v.push_back(100 * i + j);
		}
	}
	fill(&b[0][0], &b[0][0] + 3000 * 3000, 1e9);
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			for(int d = 0; d < 4; d++){
				int ny = i + dy[d];
				int nx = j + dx[d];
				if(ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
				int h = abs(a[i][j] - a[ny][nx]);
				if(h <= t){
					if(a[i][j] >= a[ny][nx]) b[i * 100 + j][ny * 100 + nx] = 1;
					else{
						b[i * 100 + j][ny * 100 + nx] = h * h;
					}
				}
			}
		}
	}
	for(int k : v){
		for(int i : v){
			for(int j : v){
				if(b[i][j] > b[i][k] + b[k][j]){
					b[i][j] = b[i][k] + b[k][j];
				}
			}
		}
	}
	ret = a[0][0];
	
	for(int i : v){
		if(b[0][i] + b[i][0] <= d){
			ret = max(ret, a[i / 100][i % 100]);
		}
	}
	cout << ret << "\n";
}