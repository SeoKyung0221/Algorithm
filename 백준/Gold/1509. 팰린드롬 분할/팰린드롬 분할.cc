#include<bits/stdc++.h>
using namespace std;
string s;
int dp[2504][2504], dp2[2504];

int solve(int idx){
	if(idx == s.size()) return 0;
	
	int &ret = dp2[idx];
	if(ret != 1e9) return ret;
	
	for(int i = 1; i <= s.size(); i++){
		if(dp[idx][i]) ret = min(ret, solve(idx + i) + 1);
	}
	return ret;
}
int main(){
	fill(dp2, dp2 + 2504, 1e9);
	cin >> s;
	for(int i = 0; i < s.size(); i++){
		dp[i][1] = 1;
	}
	for(int i = 0; i < s.size()-1; i++){
		if(s[i] == s[i+1]) dp[i][2] = 1;
	}
	for(int _size = 3; _size <= s.size(); _size++){
		for(int i = 0; i + _size <= s.size(); i++){
			if(s[i] == s[i+_size-1] && dp[i+1][_size-2]){
				dp[i][_size] = 1;
			}
		}
	}
	cout << solve(0) << "\n";
}