#include<bits/stdc++.h>
using namespace std;
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
int n, m, k, a[21][21], visited[21][21], sy, sx, y, x;
pair<int, int> arrive[404];
struct B{
	int num, py, px;
};
vector<B> person;

bool cmp(B a, B b){
	if(visited[a.py][a.px] == visited[b.py][b.px]){
		if(a.py == b.py) return a.px < b.px;
		else return a.py < b.py;
	}else return visited[a.py][a.px] < visited[b.py][b.px];
}
void shortCut(){
	memset(visited, 0, sizeof(visited));
	queue<pair<int, int>> q;
	visited[sy][sx] = 1;
	q.push({sy, sx});
	
	while(q.size()){
		tie(y, x) = q.front();
		q.pop();
		for(int i = 0; i < 4; i++){
			int ny = y + dy[i];
			int nx = x + dx[i];
			if(ny < 0 || ny >= n || nx < 0 || nx >= n || a[ny][nx] == 1 || visited[ny][nx]) continue;
			visited[ny][nx] = visited[y][x] + 1;
			q.push({ny, nx});
		}
	}
}
	// 현재 택시로부터 모든 거리 찾기 
	// -> person정렬 후, 첫번째 사람에게 이동( 항상 연료 확인 ) 
	// -> 목적지까지 이동할 수 있는가 확인 후 이동할 수 있다면 연료 충전.
	// -> 반복하기전에 모든 승객을 태웠는가 확인. 
void solve(){
	shortCut();
	sort(person.begin(), person.end(), cmp);	
	
	if(k >= visited[person[0].py][person[0].px] - 1 && visited[person[0].py][person[0].px] != 0){ // 승객에게 이동이 가능하다면 
		k -= (visited[person[0].py][person[0].px] - 1);
		sy = person[0].py;
		sx = person[0].px;
	}else{ // 연료가 부족하다면 그냥 실패로 바로 함수 종료. 
		cout << -1 << "\n";
		exit(0);
	}
	
	shortCut(); // 현재 위치에서 최단거리 다시.
	
	if((k >= visited[arrive[person[0].num].first][arrive[person[0].num].second] - 1) && visited[arrive[person[0].num].first][arrive[person[0].num].second] != 0){ // 목적지까지 갈 수 있다면 
		k -= visited[arrive[person[0].num].first][arrive[person[0].num].second] - 1;
		tie(sy, sx) = arrive[person[0].num];
		k += 2 * (visited[arrive[person[0].num].first][arrive[person[0].num].second] - 1);
		
		person.erase(person.begin(), person.begin() + 1);
	}else{
		cout << -1 << "\n";
		exit(0);
	}
}

int main(){
	cin >> n >> m >> k;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin >> a[i][j];
		}
	}
	cin >> sy >> sx;
	sy--; sx--;
	for(int i = 1; i <= m; i++){
		cin >> y >> x;
		y--; x--;
		person.push_back({i, y, x});
		
		cin >> y >> x;
		y--; x--;
		arrive[i] = {y, x};
	}
	int flag = 0;
	while(true){
		solve();
		if(person.size() == 0){
			flag = 1;
			break;
		}
	}
	if(flag) cout << k << "\n";
	
	return 0;	
}