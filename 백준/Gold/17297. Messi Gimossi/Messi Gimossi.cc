#include<bits/stdc++.h>
using namespace std;
int n, dp[40];
string s = "Messi Gimossi";
int main(){
	cin >> n;
	
	dp[1] = 5;
	dp[2] = 13;
	for(int i = 3; i < 40; i++){
		dp[i] = dp[i-1] + dp[i-2] + 1;
	}
	for(int i = 39; i >= 2; i--){
		if(n > dp[i]) n -= (dp[i] + 1);
	}
	if(n == 6 || n == 0) cout << "Messi Messi Gimossi\n";
	else cout << s[n - 1] << "\n";
}