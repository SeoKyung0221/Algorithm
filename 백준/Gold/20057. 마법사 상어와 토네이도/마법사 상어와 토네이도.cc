#include<bits/stdc++.h>
using namespace std;
const int dy[] = {0, 1, 0, -1};
const int dx[] = {-1, 0, 1, 0};
const int wind_dy[4][10] = {
{-1, 1, -2, 2, 0, -1, 1, -1, 1},
{-1, -1, 0, 0, 2, 0, 0, 1, 1},
{1, -1, 2, -2, 0, 1, -1, 1, -1},
{1, 1, 0, 0, -2, 0, 0, -1, -1}
};
const int wind_dx[4][10] = {
{1, 1, 0, 0, -2, 0, 0, -1, -1},
{-1, 1, -2, 2, 0, -1, 1, -1, 1},
{-1, -1, 0, 0, 2, 0, 0, 1, 1},
{1, -1, 2, -2, 0, 1, -1, 1, -1}
};
const int wind[] = {1, 1, 2, 2, 5, 7, 7, 10, 10};
int n, a[504][504], visited[504][504], dir = -1, cy, cx, ret;

void moveSand(int y, int x){
	int sand = a[y][x], sum = 0;
	for(int i = 0; i < 9; i++){
		int ny = y + wind_dy[dir][i];
		int nx = x + wind_dx[dir][i];
		if(ny < 0 || ny >= n || nx < 0 || nx >= n){
			ret += (sand * wind[i]) / 100;
			sum += (sand * wind[i]) / 100;
			continue;
		}
		a[ny][nx] += (sand * wind[i]) / 100;
		sum += (sand * wind[i]) / 100;
	}
	int ny = y + dy[dir];
	int nx = x + dx[dir];
	if(ny < 0 || ny >= n || nx < 0 || nx >= n){
		ret += sand - sum;
	}else a[ny][nx] += sand - sum;
	a[y][x] = 0;
	
	return;
}
void move(int y, int x){
	int temp_dir = (dir + 1) % 4;
	int ny = y + dy[temp_dir];
	int nx = x + dx[temp_dir];
	if(visited[ny][nx]){
		ny = y + dy[dir];
		nx = x + dx[dir];
	}else dir = temp_dir;
	
	visited[ny][nx] = 1;
	if(a[ny][nx]) moveSand(ny, nx);
	
	cy = ny; cx = nx;
	return;
}
int main(){
	cin >> n;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin >> a[i][j];
		}
	}
	cy = n / 2, cx = n / 2;
	visited[cy][cx] = 1;
	while(!(cy == 0 && cx == 0)){
		move(cy, cx);
	}
	cout << ret << "\n";
}

