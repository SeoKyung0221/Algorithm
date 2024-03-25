#include<bits/stdc++.h>
using namespace std;
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
int n, m, a[54][54], visited[54][54], ret = 1e9;
vector<pair<int, int>> v;

int check_time(vector<int> b){
	int empty_cnt = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(a[i][j] == 0) empty_cnt++;
		}
	}
	memset(visited, 0, sizeof(visited));
	int cnt = 0;
	int ans = 0;
	queue<pair<int, int>> q;
	for(int i : b){
		q.push(v[i]);
		visited[v[i].first][v[i].second] = 1;
	}
	while(q.size()){
		if(empty_cnt == cnt) break;
		ans++;
		int qSize = q.size();
		for(int j = 0; j < qSize; j++){
			int y, x;
			tie(y, x) = q.front();
			q.pop();
			for(int i = 0; i < 4; i++){
				int ny = y + dy[i];
				int nx = x + dx[i];
				if(ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
				if(a[ny][nx] == 1) continue;
				if(visited[ny][nx]) continue;
				visited[ny][nx] = 1;
				q.push({ny, nx});
				if(a[ny][nx] == 0) cnt++;
			}
		}
	}
	if(empty_cnt == cnt) return ans;
	else return 1e9;
}
void combi(int start, vector<int> &b){
	if(b.size() == m){
		ret = min(ret, check_time(b));
		return;
	}
	for(int i = start + 1; i < v.size(); i++){
		b.push_back(i);
		combi(i, b);
		b.pop_back();
	}
	return;
}
int main(){
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin >> a[i][j];
			if(a[i][j] == 2) v.push_back({i, j});
		}
	}
	vector<int> b;
	combi(-1, b);
	
	if(ret == 1e9) cout << "-1\n";
	else cout << ret << "\n";
	return 0;
}