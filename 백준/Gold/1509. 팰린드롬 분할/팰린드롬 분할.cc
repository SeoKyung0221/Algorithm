#include<bits/stdc++.h>
using namespace std;
int n, dp[2504][2504], dp2[2504];
string s;

int go(int here){
	if(here == n) return 0;
	
	int &ret = dp2[here];
	if(ret != 1e9) return ret;
	
	for(int size = 1; size + here - 1 < n; size++){
		if(dp[here][size]) ret = min(ret, go(here + size) + 1);
	}
	return ret;
}
int main(){
	cin >> s;
	n = s.size();
	
	for(int i = 0; i < n; i++){
		dp[i][1] = 1;
	}
	for(int i = 0; i < n - 1; i++){
		if(s[i] == s[i + 1]) dp[i][2] = 1;
	}
	for(int size = 3; size <= n; size++){
		for(int i = 0; i + size - 1 < n; i++){
			if(s[i] == s[i + size - 1] && dp[i + 1][size - 2]) dp[i][size] = 1;
		}
	}
	fill(dp2, dp2 + 2504, 1e9);
	
	cout << go(0) << "\n";
	return 0;
}