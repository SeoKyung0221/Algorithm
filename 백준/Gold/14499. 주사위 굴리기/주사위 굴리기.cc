#include<bits/stdc++.h>
using namespace std;
const int dy[] = {0, 0, -1, 1};
const int dx[] = {1, -1, 0, 0};
int n, m, y, x, k, dice[7], a[24][24], dir;

void move(int dir){
	int underValue = dice[6];
	if(dir == 1){
		dice[6] = dice[3];
		dice[3] = dice[1];
		dice[1] = dice[4];
		dice[4] = underValue;
	}else if(dir == 2){
		dice[6] = dice[4];
		dice[4] = dice[1];
		dice[1] = dice[3];
		dice[3] = underValue;
	}else if(dir == 3){
		dice[6] = dice[2];
		dice[2] = dice[1];
		dice[1] = dice[5];
		dice[5] = underValue;
	}else{
		dice[6] = dice[5];
		dice[5] = dice[1];
		dice[1] = dice[2];
		dice[2] = underValue;
	}
}
int main(){
	cin >> n >> m >> y >> x >> k;
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin >> a[i][j];
		}
	}
	
	dice[6] = 0;
	
	for(int i = 0; i < k; i++){
		cin >> dir;
		dir--;
		
		int ny = y + dy[dir];
		int nx = x + dx[dir];
		if(ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
		move(dir + 1);
		if(a[ny][nx] == 0){
			a[ny][nx] = dice[6];
			cout << dice[1] << "\n";
		}else{
			dice[6] = a[ny][nx];
			a[ny][nx] = 0;
			cout << dice[1] << "\n";
		}
		y = ny;
		x = nx;
	}
	return 0;
}