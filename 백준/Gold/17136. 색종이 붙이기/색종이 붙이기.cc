#include<bits/stdc++.h>
using namespace std;
int n = 10, a[11][11], ret = 1e9;
map<int, int> mp;

bool check(int y, int x, int cnt){
	for(int i = y; i < y + cnt; i++){
		for(int j = x; j < x + cnt; j++){
			if(a[i][j] == 0) return false;
		}
	}
	return true;
}

void draw(int y, int x, int cnt, int value){
	for(int i = y; i < y + cnt; i++){
		for(int j = x; j < x + cnt; j++){
			a[i][j] = value;
		}
	}
}

void go(int y, int x, int cnt){
	if(cnt >= ret) return;
	
	if(x == n){
		go(y + 1, 0, cnt);
		return;
	}
	if(y == n){
		ret = min(ret, cnt);
		return;
	}
	
	if(a[y][x] == 0){
		go(y, x + 1, cnt);
		return;
	}else{
		for(int i = 5; i >= 1; i--){
			if(mp[i] == 5) continue;
			if(check(y, x, i)){
				mp[i]++;
				draw(y, x, i, 0);
				go(y, x + i, cnt + 1);
				draw(y, x, i, 1);
				mp[i]--;
			}
		}
	}
}
int main(){
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin >> a[i][j];
		}
	}
	go(0, 0, 0);
	
	cout << (ret == 1e9 ? -1 : ret) << "\n";
}