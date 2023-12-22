#include<bits/stdc++.h>
using namespace std;
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
int n, m, sy, sx, y, x, visited_water[1504][1504], visited_swan[1504][1504], ret;
char a[1504][1504];
queue<pair<int, int>> water_Q, swan_Q, water_tempQ, swan_tempQ;

void Qclear(queue<pair<int ,int>> &q){
	queue<pair<int, int>> p;
	q = p;
}
bool move_swan(){
	while(swan_Q.size()){
		tie(y, x) = swan_Q.front();
		swan_Q.pop();
		for(int i = 0; i < 4; i++){
			int ny = y + dy[i];
			int nx = x + dx[i];
			if(ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
			if(visited_swan[ny][nx]) continue;
			if(a[ny][nx] == '.'){
				visited_swan[ny][nx] = 1;
				swan_Q.push({ny, nx});
			}else if(a[ny][nx] == 'X'){
				visited_swan[ny][nx] = 1;
				swan_tempQ.push({ny, nx});
			}else if(a[ny][nx] == 'L') return true;
		}
	}
	return false;
}
void water_melting(){
	while(water_Q.size()){
		tie(y, x) = water_Q.front();
		water_Q.pop();
		for(int i = 0; i < 4; i++){
			int ny = y + dy[i];
			int nx = x + dx[i];
			if(ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
			if(visited_water[ny][nx]) continue;
			if(a[ny][nx] == 'X'){
				visited_water[ny][nx] = 1;
				water_tempQ.push({ny, nx});
				a[ny][nx] = '.';
			}
		}
	}
}
int main(){
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin >> a[i][j];
			if(a[i][j] == 'L'){
				sy = i;
				sx = j;
			}
			if(a[i][j] == 'L' || a[i][j] == '.'){
				visited_water[1504][1504] = 1;
				water_Q.push({i, j});
			}
		}
	}
	visited_swan[sy][sx] = 1;
	swan_Q.push({sy, sx});
	while(true){
		if(move_swan()) break;
		water_melting();
		swan_Q = swan_tempQ;
		water_Q = water_tempQ;
		Qclear(swan_tempQ);
		Qclear(water_tempQ);
		ret++;
	}
	cout << ret << "\n";
}