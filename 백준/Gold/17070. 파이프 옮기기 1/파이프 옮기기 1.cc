#include<bits/stdc++.h>
using namespace std;
const int INF = 1000004;
int n, dp[20][20][3], a[20][20];
const int dy[] = {0, 1, 1};
const int dx[] = {1, 1, 0};

int go(int y, int x, int mod){
	if(y < 0 || y >= n || x < 0 || x >= n) return 0;
	if(y == n - 1 && x == n - 1) return 1;
	
	int &ret = dp[y][x][mod];
	if(ret != 0) return ret;
	
	if(mod == 0){
		if(a[y][x+1] == 0){
			ret += go(y, x+1, 0);
		}
		int flag = 1;
		for(int i = 0; i < 3; i++){
			int ny = y + dy[i];
			int nx = x + dx[i];
			if(a[ny][nx] == 1) flag = 0;
		}
		if(flag) ret += go(y+1, x+1, 2);
	}else if(mod == 1){
		if(a[y+1][x] == 0){
			ret += go(y+1, x, 1);
		}
		int flag = 1;
		for(int i = 0; i < 3; i++){
			int ny = y + dy[i];
			int nx = x + dx[i];
			if(a[ny][nx] == 1) flag = 0;
		}
		if(flag) ret += go(y+1, x+1, 2);
	}else{
		if(a[y][x+1] == 0){
			ret += go(y, x+1, 0);
		}
		if(a[y+1][x] == 0){
			ret += go(y+1, x, 1);
		}
		int flag = 1;
		for(int i = 0; i < 3; i++){
			int ny = y + dy[i];
			int nx = x + dx[i];
			if(a[ny][nx] == 1) flag = 0;
		}
		if(flag) ret += go(y+1, x+1, 2);
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
	cout << go(0, 1, 0) << "\n";
}
