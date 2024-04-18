#include<bits/stdc++.h>
using namespace std;
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
int n, m, a[68][68], visited[68][68], l, ret, ret2;

void _rotate(vector<vector<int>> &b){
	vector<vector<int>> temp(l, vector<int>(l, 0));
		
	for(int i = 0; i < l; i++){
		for(int j = 0; j < l; j++){
			temp[i][j] = b[l - 1 - j][i];
		}
	}
	b = temp;
	return;
}
void _melt(){
	int temp[68][68] = {0, };
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			temp[i][j] = a[i][j];
		}
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(a[i][j] == 0) continue;
			int cnt = 0;
			for(int k = 0; k < 4; k++){
				int ny = i + dy[k];
				int nx = j + dx[k];
				if(ny < 0 || ny >= n || nx < 0 || nx >= n || a[ny][nx] == 0) continue;
				cnt++;
			}
			if(cnt < 3){
				temp[i][j] = max(0, a[i][j] - 1);
			}
		}
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			a[i][j] = temp[i][j];
		}
	}
}
void solve(){
	// 격자 나누기
	// 격자들 회전하기
	// 얼음 녹이기 
	for(int i = 0; i < n; i += l){
		for(int j = 0; j < n; j += l){
			vector<vector<int>> b(l, vector<int>(l, 0));
			for(int p = i; p < i + l; p++){
				for(int q = j; q < j + l; q++){
					b[p - i][q - j] = a[p][q];
				}
			}
			_rotate(b);
			
			for(int p = i; p < i + l; p++){
				for(int q = j; q < j + l; q++){
					a[p][q] = b[p - i][q - j];
				}
			}
		}
	}

	_melt();

	return;
}
int dfs(int y, int x){
	int ans = 1;
	
	visited[y][x] = 1;
	
	for(int i = 0; i < 4; i++){
		int ny = y + dy[i];
		int nx = x + dx[i];
		if(ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
		if(visited[ny][nx]) continue;
		if(a[ny][nx] == 0) continue;
		ans += dfs(ny, nx);
	}
	
	return ans;
}
void ice(){
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(a[i][j] == 0) continue;
			memset(visited, 0, sizeof(visited));
			ret2 = max(ret2, dfs(i, j));
		}
	}
}
int main(){
	cin >> n >> m;
	n = (int)(pow(2, n));
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin >> a[i][j];
		}
	}
	for(int i = 0; i < m; i++){
		cin >> l;
		l = (int)(pow(2, l));
		solve();
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			ret += a[i][j];
		}
	}
	cout << ret << "\n";
	
	ice();
	
	cout << ret2 << "\n";
	
	return 0;
}