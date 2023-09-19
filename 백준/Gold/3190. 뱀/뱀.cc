#include<bits/stdc++.h>
using namespace std;
#define time aaaa
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
int n, k, a, b, l, y, x, time = 1, dir = 1, visited[104][104], ap[104][104], idx;
char c;
vector<pair<int, int>> v;

int main(){
	cin >> n >> k;
	for(int i = 0; i < k; i++){
		cin >> a >> b;
		ap[--a][--b] = 1;
	}
	cin >> l;
	for(int i = 0; i < l; i++){
		cin >> x >> c;
		if(c == 'D') v.push_back({x, 1});
		else v.push_back({x, 3});
	}
	deque<pair<int, int>> dq;
	visited[0][0] = 1;
	dq.push_front({0, 0});
	while(dq.size()){
		tie(y, x) = dq.front();
		int ny = y + dy[dir];
		int nx = x + dx[dir];
		if(ny < 0 || nx < 0 || ny >= n || nx >= n || visited[ny][nx]){
			break;
		}
		if(ap[ny][nx]){
			ap[ny][nx] = 0;
		}else{
			visited[dq.back().first][dq.back().second] = 0;
			dq.pop_back();
		}
		dq.push_front({ny,nx});
		visited[ny][nx] = 1;
		if(time == v[idx].first){
			dir = (dir + v[idx].second) % 4;
			idx++;
		}
		time++;
	}
	cout << time << "\n";
}