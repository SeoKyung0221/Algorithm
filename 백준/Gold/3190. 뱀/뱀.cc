#include<bits/stdc++.h>
using namespace std;
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
int n, k, a[104][104], visited[104][104], y, l, x, cnt, dir = 1, _time;
char c;
vector<pair<int, int>> v;
deque<pair<int, int>> dq;

int main(){
	cin >> n >> k;
	for(int i = 0; i < k; i++){
		cin >> y >> x;
		y--; x--;
		a[y][x] = 1;
	}
	cin >> l;
	for(int i = 0; i < l; i++){
		cin >> x >> c;
		if(c == 'D') v.push_back({x, 1});
		else v.push_back({x, 3});
	}
	visited[0][0] = 1;
	dq.push_back({0, 0});
	
	while(true){
		_time++;
		tie(y, x) = dq.front();
		
		int ny = y + dy[dir];
		int nx = x + dx[dir];
		if(ny < 0 || ny >= n || nx < 0 || nx >= n || visited[ny][nx]) break;
		
		if(a[ny][nx]){
			a[ny][nx] = 0;
		}else{
			visited[dq.back().first][dq.back().second] = 0;
			dq.pop_back();
		}
		dq.push_front({ny, nx});
		visited[ny][nx] = 1;
		
		if(_time == v[cnt].first){
			dir = (dir + v[cnt].second) % 4;
			cnt++;
		}
	}
	cout << _time << "\n";
}