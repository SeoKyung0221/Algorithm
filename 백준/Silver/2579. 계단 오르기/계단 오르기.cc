#include<bits/stdc++.h>
using namespace std;
int n, a[304], dp[304];

int main(){
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	dp[0] = a[0];
	dp[1] = a[0] + a[1];
	dp[2] = max(dp[0] + a[2], dp[1] + a[2]);
	for(int i = 2; i < n; i++){
		dp[i] = max(dp[i-3] + a[i-1] + a[i], dp[i-2] + a[i]);
	}
	cout << dp[n-1] << "\n";
}