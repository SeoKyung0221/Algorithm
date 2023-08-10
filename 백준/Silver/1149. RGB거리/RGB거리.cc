#include<bits/stdc++.h>
using namespace std;
int n, a, b, c, dp[1004][4];

int main(){
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> a >> b >> c;
		dp[i][0] = a;
		dp[i][1] = b;
		dp[i][2] = c;
	}
	for(int i = 1; i < n; i++){
		dp[i][0] += min(dp[i-1][1], dp[i-1][2]);
		dp[i][1] += min(dp[i-1][0], dp[i-1][2]);
		dp[i][2] += min(dp[i-1][0], dp[i-1][1]);
	}
	cout << min({dp[n-1][0], dp[n-1][1], dp[n-1][2]});
}