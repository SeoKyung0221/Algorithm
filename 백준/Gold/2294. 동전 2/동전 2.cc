#include<bits/stdc++.h>
using namespace std;
int n, k, temp, dp[10004];

int main(){
	fill(dp, dp + 10004, 1e9);
	dp[0] = 0;
	cin >> n >> k;
	for(int i = 0; i < n; i++){
		cin >> temp;
		for(int j = temp; j <= k; j++){
			dp[j] = min(dp[j], dp[j - temp] + 1);
		}
	}
	cout << ((dp[k] == 1e9) ? -1 : dp[k]) << "\n";
}