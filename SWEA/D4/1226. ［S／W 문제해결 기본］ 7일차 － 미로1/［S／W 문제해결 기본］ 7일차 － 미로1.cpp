#include<bits/stdc++.h>
using namespace std;
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
int te, a[16][16], sy, sx, ey, ex, visited[16][16];

int main(){
	for(int t = 0; t < 10; t++){
		cin >> te;
		
		memset(visited, 0, sizeof(visited));
		for(int i = 0; i < 16; i++){
			for(int j = 0; j < 16; j++){
				scanf("%1d", &a[i][j]);
				if(a[i][j] == 2){
					sy = i;
					sx = j;
				}
				if(a[i][j] == 3){
					ey = i;
					ex = j;
				}
			}
		}
		
		queue<pair<int, int>> q;
		q.push({sy, sx});
		visited[sy][sx] = 1;
		
		while(q.size()){
			int y, x;
			tie(y, x) = q.front();
			q.pop();
			for(int i = 0; i < 4; i++){
				int ny = y + dy[i];
				int nx = x + dx[i];
				if(ny < 0 || ny >= 16 || nx < 0 || nx >= 16) continue;
				if(visited[ny][nx]) continue;
				if(a[ny][nx] == 1) continue;
				visited[ny][nx] = 1;
				q.push({ny, nx});
			}
			if(visited[ey][ex]) break;
		}		
		if(visited[ey][ex]) cout << "#" << te << " 1" << "\n";
		else cout << "#" << te << " 0" << "\n"; 
	}
}