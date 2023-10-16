#include<bits/stdc++.h>
using namespace std;
int m, dp[40];
string s = "Messi Gimossi";

int main(){
	cin >> m;
	dp[1] = 5;
	dp[2] = 13;
	for(int i = 3; i <= 39; i++){
		dp[i] = dp[i-1] + dp[i-2] + 1;
	}
	for(int i = 39; i >= 2; i--){
		if(m > dp[i]) m -= dp[i] + 1;
	}
	if(m == 0 || m == 6) cout << "Messi Messi Gimossi" << "\n";
	else cout << s[m-1] << "\n";
}