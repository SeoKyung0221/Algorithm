#include<bits/stdc++.h>
using namespace std;
int n, a[10004], dp[10004], ret;

int main(){
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	dp[1] = a[1];
	dp[2] = a[1] + a[2];
	
	for(int i = 3; i <= n; i++){
		dp[i] = max({dp[i-1], dp[i-3] + a[i-1] + a[i], dp[i-2] + a[i]});
	}
	cout << dp[n] << "\n";
}