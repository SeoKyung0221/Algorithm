#include<bits/stdc++.h>
using namespace std;
int n, k, temp, dp[10004];

int main(){
	memset(dp, 0, sizeof(dp));
	cin >> n >> k;
	
	for(int i = 0; i < n; i++){
		cin >> temp;
		dp[0] = 1;
		for(int j = temp; j <= k; j++){
			dp[j] += dp[j - temp];
		}
	}
	cout << dp[k] << "\n";
}