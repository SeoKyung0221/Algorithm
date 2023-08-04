#include<bits/stdc++.h>
using namespace std;
int n, m, c, a[17], dp[11][1 << 14][24];

int solve(int idx, int j, int w){
	if(idx == m) return 0;
	
	int &ret = dp[idx][j][w];
	if(ret != -1) return ret;
	
	ret = max(ret, solve(idx+1, j, c));
	for(int i = 0; i < n; i++){
		int flag = 1, flag2 = 0;
		if((1 << i) & j) flag = 0;
		if(a[i] <= w) flag2 = 1;
		if(flag && flag2) ret = max(ret, solve(idx, (1 << i) | j, w - a[i]) + 1);
	}
	return ret;
}
int main(){
	fill(&dp[0][0][0], &dp[0][0][0] + 11 * (1 << 14) * 24, -1);
	cin >> n >> m >> c;
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	cout << solve(0, 0, c) << "\n";
}