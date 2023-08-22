#include<bits/stdc++.h>
using namespace std;
const int mod = 1000007;
int n, m, c, a[54][54], b, d, dp[54][54][54][54];

int go(int y, int x, int cnt, int prev){
	if(y > n || x > m) return 0;
	if(y == n && x == m){
		if(cnt == 0 && a[y][x] == 0) return 1;
		if(cnt == 1 && a[y][x] > prev) return 1;
		return 0;
	}
	
	int &ret = dp[y][x][cnt][prev];
	if(ret != -1) return ret;
	
	ret = 0;
	if(a[y][x] == 0){
		ret = go(y + 1, x, cnt, prev) + go(y, x + 1, cnt, prev);
		ret %= mod;
	}else if(a[y][x] > prev){
		ret = go(y + 1, x, cnt - 1, a[y][x]) + go(y, x + 1, cnt - 1, a[y][x]);
		ret %= mod;
	}
	return ret;
}
int main(){
	fill(&dp[0][0][0][0], &dp[0][0][0][0] + 54 * 54 * 54 * 54, -1);
	cin >> n >> m >> c;
	for(int i = 1; i <= c; i++){
		cin >> b >> d;
		a[b][d] = i;
	}
	for(int i = 0; i <= c; i++){
		cout << go(1, 1, i, 0) << " ";
	}
}