#include<bits/stdc++.h>
using namespace std;
const int INF = 1e9;
int n, k, num, dp[10004];

int main(){
	fill(dp, dp+10004, INF);
	cin >> n >> k;
	dp[0] = 0;
	for(int i = 0; i < n; i++){
		cin >> num;
		for(int j = num; j <= k; j++){
			dp[j] = min(dp[j], dp[j-num] + 1);
		}
	}
	cout << ((dp[k] == INF) ? -1 : dp[k]) << "\n";
}