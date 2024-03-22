#include<bits/stdc++.h>
using namespace std;
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
int n, a[21][21], visited[21][21], sy, sx, _size = 2, ret;
vector<tuple<int, int, int>> v;

bool cmp(tuple<int, int, int> a, tuple<int, int, int> b){
	if(get<2>(a) == get<2>(b)){
		if(get<0>(a) == get<0>(b)) return get<1>(a) < get<1>(b);
		else return get<0>(a) < get<0>(b);
	}else return get<2>(a) < get<2>(b);
}

int main(){
	cin >> n;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin >> a[i][j];
			if(a[i][j] == 9){
				sy = i;
				sx = j;
				a[i][j] = 0;
			}
		}
	}
	int cnt = 0;
	while(true){	
		v.clear();
		memset(visited, 0, sizeof(visited));
		
		visited[sy][sx] = 1;
		queue<pair<int, int>> q;
		q.push({sy, sx});
		
		while(q.size()){
			int y, x;
			tie(y, x) = q.front();
			q.pop();
			for(int i = 0; i < 4; i++){
				int ny = y + dy[i];
				int nx = x + dx[i];
				if(ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
				if(visited[ny][nx]) continue;
				if(a[ny][nx] > _size) continue;
				visited[ny][nx] = visited[y][x] + 1;
				q.push({ny, nx});
				if(a[ny][nx] >= 1 && a[ny][nx] < _size){
					v.push_back(make_tuple(ny, nx, visited[ny][nx] - 1));
				}
			}
		} // 최단거리 도출 및 물고기 위치 적립. 
		if(v.size() == 0) break;
		
		sort(v.begin(), v.end(), cmp); // 물고기 최단거리 적립. 
		sy = get<0>(v[0]);
		sx = get<1>(v[0]);
		a[get<0>(v[0])][get<1>(v[0])] = 0;
		
		cnt++;
		if(cnt == _size){
			_size += 1;
			cnt = 0;
		}
		ret += get<2>(v[0]);
	}
	cout << ret << "\n";
}