#include<bits/stdc++.h>
using namespace std;
const int dy[] = {-1, -1, -1, 0, 1, 1, 1, 0};
const int dx[] = {-1, 0, 1, 1, 1, 0, -1, -1};
int te, n, visited[304][304], ret;
char a[304][304];

void bfs(int y, int x){
	queue<pair<int, int>> q;
	q.push({y, x});
	
	while(q.size()){
		tie(y, x) = q.front();
		q.pop();
		for(int i = 0; i < 8; i++){
			int ny = y + dy[i];
			int nx = x + dx[i];
			if(ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
			if(a[ny][nx] == '*') continue;
			if(visited[ny][nx]) continue;
			visited[ny][nx] = 1;
			if(a[ny][nx] == '0') q.push({ny, nx});
		}
	}
}
int main(){
	cin >> te;
	for(int t = 1; t <= te; t++){
		memset(visited, 0, sizeof(visited));
		ret = 0;
		
		cin >> n;
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				scanf(" %c", &a[i][j]);
			}
		}
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				if(a[i][j] == '*') continue;
				int cnt = 0;
				for(int k = 0; k < 8; k++){
					int ny = i + dy[k];
					int nx = j + dx[k];
					if(ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
					if(a[ny][nx] == '*') cnt++;
				}
				a[i][j] = cnt + '0';
			}
		}
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				if(!visited[i][j] && a[i][j] == '0'){
					ret++;
					visited[i][j] = 1;
					bfs(i, j);
				}
			}
		}
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				if(visited[i][j] == 0 && a[i][j] != '*') ret++;
			}
		}
		cout << "#" << t << " " << ret << "\n";
	}
}