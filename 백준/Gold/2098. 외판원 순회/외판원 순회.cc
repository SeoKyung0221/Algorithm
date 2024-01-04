#include<bits/stdc++.h>
using namespace std;
int n, dp[18][1 << 18], a[18][18];

int go(int idx, int visited){
	if(visited == (1 << n) - 1){
		return a[idx][0] ? a[idx][0] : 1e9;
	}
	int &ret = dp[idx][visited];
	if(ret != -1) return ret;
	
	ret = 1e9;
	
	for(int i = 0; i < n; i++){
		if(visited & (1 << i)) continue;
		if(a[idx][i] == 0) continue;
		ret = min(ret, go(i, visited | (1 << i)) + a[idx][i]);
	}
	return ret;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
//	fill(&dp[0][0], &dp[0][0] + 18 * (1 << 18), 1e9);
	memset(dp, -1, sizeof(dp));
	cin >> n;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin >> a[i][j];
		}
	}
	cout << go(0, 1) << "\n";
}