#include<bits/stdc++.h>
using namespace std;
int n, m, h, visited[34][14], a, b, ret = 1e9;

bool check(){
	for(int i = 1; i <= n; i++){
		int start = i;
		for(int j = 1; j <= h; j++){
			if(visited[j][start-1]) start--;
			else if(visited[j][start]) start++;
		}
		if(start != i) return false;
	}
	return true;
}
void go(int idx, int cnt){
	if(cnt > 3 || cnt >= ret){
		return;
	}
	if(check()){
		ret = min(ret, cnt);
		return;
	}
	for(int i = idx; i <= h; i++){
		for(int j = 1; j <= n; j++){
			if(visited[i][j-1] || visited[i][j] || visited[i][j+1]) continue;
			visited[i][j] = 1;
			go(i, cnt + 1);
			visited[i][j] = 0;
		}
	}
}
int main(){
	cin >> n >> m >> h;
	for(int i = 0; i < m; i++){
		cin >> a >> b;
		visited[a][b] = 1;
	}
	
	go(1, 0);
	
	cout << ((ret == 1e9) ? -1 : ret) << "\n";
}