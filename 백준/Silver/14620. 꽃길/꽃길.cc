#include<bits/stdc++.h>
using namespace std;
int ret = 3000;
int n, a[11][11], visited[11][11], x4, y4, x2, y2, x3, y3;
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};
bool check;
vector<pair<int,int>> v;
// 1. 꽃을 피우는 경우의 수 / 2. 비용을 구하는 경우의 수. 

void go(int y, int x){ // 꽃잎에 대한 방문 처리. 
	if(y <= 0 || y >= n-1 || x <= 0 || x >= n-1){
		check = false;
		return;
	}
	if(visited[y][x] || visited[y+1][x] || visited[y-1][x] || visited[y][x+1] || visited[y][x-1]){
		check = false;
		return;
	}
	visited[y][x] = 1;
	for(int i = 0; i < 4; i++){
		int ny = y + dy[i];
		int nx = x + dx[i];
		visited[ny][nx] = 1;
	}
	return;
}

int charge(){
	int sum = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(visited[i][j] == 1)
				sum += visited[i][j] * a[i][j];
		}
	}
	return sum;
}
int main(){
	cin >> n;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin >> a[i][j];
		}
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
		v.push_back({i, j}); // 여기서 3개뽑기. 
		}	
	}
	for(int i = 0; i < n*n; i++){
		for(int j = i+1; j < n*n; j++){
			for(int k = j+1; k < n*n; k++){
				fill(&visited[0][0], &visited[0][0]+11*11, 0);
				check = true;
				tie(y4, x4) = v[i];
				tie(y2, x2) = v[j];
				tie(y3, x3) = v[k];
				go(y4, x4);
				go(y2, x2);
				go(y3, x3);
				if(check == false) continue;
				ret = min(ret, charge());
			}
		}
	}
	cout << ret << "\n";
	return 0;
}