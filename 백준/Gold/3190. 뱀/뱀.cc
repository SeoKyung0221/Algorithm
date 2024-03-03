#include<bits/stdc++.h>
using namespace std;
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
int n, a[104][104], visited[104][104], k, l, x, y, dir = 1, cnt, ret;
char c;

vector<pair<int, int>> v;

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
		if(c == 'D'){
			v.push_back({x, 1});
		}else v.push_back({x, 3});
	}
	deque<pair<int, int>> dq;
	dq.push_back({0, 0});
	visited[0][0] = 1;
	while(true){
		ret++;
		
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
		visited[ny][nx] = 1;
		dq.push_front({ny, nx});
		
		if(ret == v[cnt].first){
			dir = (dir + v[cnt].second) % 4;
			cnt++;
		}
	}
	cout << ret << "\n";
}