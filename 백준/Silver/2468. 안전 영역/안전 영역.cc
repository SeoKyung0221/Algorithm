#include<bits/stdc++.h>
using namespace std;
int N, a[104][104], visited[104][104], Max = 1, ret;
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

void dfs(int y, int x, int k){
	visited[y][x] = 1;
	for(int i = 0; i < 4; i++){
		int ny = y + dy[i];
		int nx = x + dx[i];
		
		if(ny < 0 || ny >= N || nx < 0 || nx >= N) continue;
		if(visited[ny][nx]) continue;
		if(a[ny][nx] <= k) continue;
		dfs(ny, nx, k);
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			cin >> a[i][j];
		}
	}
	for(int k = 1; k <= 100; k++){
		fill(&visited[0][0], &visited[0][0]+104*104, 0);
		ret = 0;
		for(int i = 0; i < N; i++){
			for(int j = 0; j < N; j++){
				if(a[i][j] > k && visited[i][j]==0){
					ret++;	dfs(i, j, k);
				}
			}
		}
		if(Max < ret){
			Max = ret;
		}
	}
	cout << Max << "\n";
}


