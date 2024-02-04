#include<bits/stdc++.h>
using namespace std;
int n, m, c, dp[54][54][54][54], a[54][54], q, w;
const int mod = 1000007;

int go(int y, int x, int prev, int cnt){
	if(y > n || x > m) return 0;
	if(y == n && x == m){
		if(cnt == 0 && a[n][m] == 0) return 1;
		if(cnt == 1 && a[n][m] > prev) return 1;
		return 0;
	}
	
	int &ret = dp[y][x][prev][cnt];
	if(ret != -1) return ret;
	
	ret = 0;
	
	if(a[y][x] == 0){
		ret = (go(y + 1, x, prev, cnt) + go(y, x+ 1, prev, cnt)) % mod;
	}else if(a[y][x] > prev){
		ret = (go(y + 1, x, a[y][x], cnt - 1) + go(y, x + 1, a[y][x], cnt - 1)) % mod;
	}
	return ret;
}

int main(){
	memset(dp, -1, sizeof(dp));
	cin >> n >> m >> c;
	for(int i = 1; i <= c; i++){
		cin >> q >> w;
		a[q][w] = i;
	}
	for(int i = 0; i <= c; i++){
		cout << go(1, 1, 0, i) << " ";
	}
}