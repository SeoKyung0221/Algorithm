#include<bits/stdc++.h>
using namespace std;
int n, k, temp, dp[10004];

int main(){
	cin >> n >> k;
	dp[0] = 1;
	for(int i = 0; i < n; i++){
		cin >> temp;
		for(int j = temp; j <= k; j++){
			dp[j] += dp[j - temp];
		}
	}
	cout << dp[k] << "\n";
}
