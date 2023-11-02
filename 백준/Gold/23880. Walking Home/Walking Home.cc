#include<bits/stdc++.h>
using namespace std;
const int dy[] = {0, 1};
const int dx[] = {1, 0};
int te, n, k, ret;
char a[54][54];

void go(int y, int x, int k, int dir){
	if(y == n-1 && x == n-1){
		ret++;
		return;
	}
	for(int i = 0; i < 2; i++){
		int ny = y + dy[i];
		int nx = x + dx[i];
		if(ny >= 0 && ny < n && nx >= 0 && nx < n && a[ny][nx] == '.'){
			if(dir == i) go(ny, nx, k, dir);
			else{
				if(k > 0) go(ny, nx, k - 1, !dir);
			}
		}
	}
}
int main(){
	cin >> te;
	while(te--){
		ret = 0;
		cin >> n >> k;
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> a[i][j];
			}
		}
		if(a[1][0] != 'H')go(1, 0, k, 1);
		if(a[0][1] != 'H')go(0, 1, k, 0);
		cout << ret << "\n";
	}
}