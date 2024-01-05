#include<bits/stdc++.h>
using namespace std;
const int dy[] = {0, 1, 1};
const int dx[] = {1, 1, 0};
int n, a[18][18], dp[18][18][4];

int go(int y, int x, int flag){
	if(y < 0 || y >= n || x < 0 || x >= n){
		return 0;
	}
	if(y == n-1 && x == n-1){
		return 1;
	}
	int &ret = dp[y][x][flag];
	if(ret != 0) return ret;
	
	if(flag == 1){
		if(a[y][x+1] != 1)	ret += go(y, x + 1, 1);

		int cnt = 1;
		for(int i = 0; i < 3; i++){
			int ny = y + dy[i];
			int nx = x + dx[i];
			if(a[ny][nx] == 1) cnt = 0;
		}
		if(cnt)	ret += go(y + 1, x + 1, 3);
	}else if(flag == 2){
		if(a[y+1][x] != 1) ret += go(y + 1, x, 2); 
		
		int cnt = 1;
		for(int i = 0; i < 3; i++){
			int ny = y + dy[i];
			int nx = x + dx[i];
			if(a[ny][nx] == 1) cnt = 0;
		}
		if(cnt) ret += go(y + 1, x + 1, 3);
	}else if(flag == 3){
		if(a[y][x+1] != 1) ret += go(y, x + 1, 1);
		if(a[y+1][x] != 1) ret += go(y + 1, x, 2);
		
		int cnt = 1;
		for(int i = 0; i < 3; i++){
			int ny = y + dy[i];
			int nx = x + dx[i];
			if(a[ny][nx] == 1) cnt = 0;
		}
		if(cnt) ret += go(y + 1, x + 1, 3);
	}
	return ret;
}
int main(){
	cin >> n;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin >> a[i][j];
		}
	}
	cout << go(0, 1, 1) << "\n";
	return 0;
}