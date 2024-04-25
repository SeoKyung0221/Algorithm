#include<bits/stdc++.h>
using namespace std;
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
int n, m, a[24][24], visited[24][24], ret;
struct B{
	int _size, rainbow, _y, _x;
};

struct cmp{
	bool operator()(B a, B b){
		if(a._size == b._size){
			if(a.rainbow == b.rainbow){
				if(a._y == b._y) return a._x > b._x;
				else return a._y > b._y;
			}else return a.rainbow > b.rainbow;
		}else return a._size > b._size;
	}
};
vector<B> v;

bool check(){
	int cnt = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(a[i][j] >= 1 && a[i][j] <= m) cnt++;
		}
	}
	return cnt < 1;
}

B bfs(int y, int x){
	visited[y][x] = 1;
	queue<pair<int, int>> q;
	q.push({y, x});
	
	B ret;
	ret._size = 1;
	if(a[y][x] == 0) ret.rainbow = 1;
	ret._y = y;
	ret._x = x;
	
	vector<pair<int, int>> vv;
	
	int temp = a[y][x];
	
	while(q.size()){
		tie(y, x) = q.front();
		q.pop();
		for(int i = 0; i < 4; i++){
			int ny = y + dy[i];
			int nx = x + dx[i];
			if(ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
			if(visited[ny][nx]) continue;
			if(a[ny][nx] == -1 || a[ny][nx] == m + 1) continue;
			if(a[ny][nx] == temp || a[ny][nx] == 0){
				if(a[ny][nx] == 0) vv.push_back({ny, nx});
				visited[ny][nx] = 1;
				ret._size += 1;
				if(a[ny][nx] == 0) ret.rainbow += 1;
				q.push({ny, nx});
				if(a[ny][nx] != 0){
					if(ret._y > ny){
					ret._y = ny;
					ret._x = nx;
					}else if(ret._y == ny){
						if(ret._x > nx){
							ret._y = ny;
							ret._x = nx;
						}
					}	
				}
			}
		}
	}
	for(auto k : vv){
		visited[k.first][k.second] = 0;
	}
	return ret;
}
void findBig(){
	memset(visited, 0, sizeof(visited));
	v.clear();
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(a[i][j] == -1 || a[i][j] == m + 1 || visited[i][j] == 1 ||a[i][j] == 0) continue;
			B temp = bfs(i, j);
			if(temp._size >= 2) v.push_back(temp);
		}
	}
	sort(v.begin(), v.end(), cmp());
}
void erasePoint(){
	int y = v[0]._y, x = v[0]._x, cnt = 0;
	memset(visited, 0, sizeof(visited));
	
	int temp = a[y][x];
	
	vector<pair<int, int>> vv;
	queue<pair<int, int>> q;
	visited[y][x] = 1;
	cnt++;
	vv.push_back({y, x});
	q.push({y, x});
	while(q.size()){
		tie(y, x) = q.front();
		q.pop();
		for(int i = 0; i < 4; i++){
			int ny = y + dy[i];
			int nx = x + dx[i];
			if(ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
			if(visited[ny][nx]) continue;
			if(a[ny][nx] == -1 || a[ny][nx] == m + 1) continue;
			if(a[ny][nx] == temp || a[ny][nx] == 0){
				cnt++;
				vv.push_back({ny, nx});
				visited[ny][nx] = 1;
				q.push({ny, nx});
			}
		}
	}
	for(auto k : vv){
		a[k.first][k.second] = m + 1;
	}
	ret += cnt * cnt;
}
void gravity(){
	for(int j = 0; j < n; j++){
		for(int i = n - 1; i >= 1; i--){
			if(a[i][j] == m + 1){
				int k = i - 1;
				while(k >= 0){
					if(a[k][j] == m + 1){
						k--;
						continue;
					}else if(a[k][j] == -1) break;
					else{
						a[i][j] = a[k][j];
						a[k][j] = m + 1;
						break;
					}
				}
			}
		}
	}
}
void _rotate(){
	int temp[24][24] = {0, };
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			temp[i][j] = a[j][n - 1 - i];
		}
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			a[i][j] = temp[i][j];
		}
	}
}
int main(){
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin >> a[i][j];
		}
	}
	while(true){
		findBig();
		if(v.size() == 0) break;
		erasePoint();
		gravity();
		_rotate();
		gravity();
	}
	cout << ret << "\n";
} 