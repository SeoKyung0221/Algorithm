#include<bits/stdc++.h>
using namespace std;
int n, a[21][21], cnt, ret = 1e9;

void solve(int x, int y, int d1, int d2, int k){
	int temp[21][21] = {0,}, b[6] = {0,}, mx = 0, mn = 1e9, cnt = k;
	
	for(int i = 0; i <= d1; i++){
		temp[x + i][y - i] = 5;
		temp[x + d2 + i][y + d2 - i] = 5;
	}
	for(int i = 0; i <= d2; i++){
		temp[x + i][y + i] = 5;
		temp[x + d1 + i][y - d1 + i] = 5;
	}

	for(int i = 1; i < x + d1; i++){
		for(int j = 1; j <= y; j++){
			if(temp[i][j] == 5) break;
			b[1] += a[i][j];
			cnt -= a[i][j];
		}
	}
	
	for(int i = 1; i <= x + d2; i++){
		for(int j = n; j > y; j--){
			if(temp[i][j] == 5) break;
			b[2] += a[i][j];
			cnt -= a[i][j];
		}
	}
	
	for(int i = x + d1; i <= n; i++){
		for(int j = 1; j < y - d1 + d2; j++){
			if(temp[i][j] == 5) break;
			b[3] += a[i][j];
			cnt -= a[i][j];
		}
	}
	
	for(int i = x + d2 + 1; i <= n; i++){
		for(int j = n; j >= y - d1 + d2; j--){
			if(temp[i][j] == 5) break;
			b[4] += a[i][j];
			cnt -= a[i][j];
		}
	}
	b[5] = cnt;
	
	for(int i = 1; i <= 5; i++){
		mx = max(mx, b[i]);
		mn = min(mn, b[i]);
	}
	ret = min(ret, mx - mn);

	return;
}
int main(){
	cin >> n;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			cin >> a[i][j];
			cnt += a[i][j];
		}
	}
	for(int x = 1; x <= n; x++){
		for(int y = 1; y <= n; y++){
			for(int d1 = 1; d1 <= n; d1++){
				for(int d2 = 1; d2 <= n; d2++){
					if(x + d1 + d2 > n || y - d1 < 1 || y + d2 > n) continue;
					solve(x, y, d1, d2, cnt);
				}
			}
		}
	}
	cout << ret << "\n";
	return 0;
}