#include<bits/stdc++.h>
using namespace std;
int n, m, dp[41], cnt[41], temp;

int go(int idx){
	if(idx >= n-1) return 1;
	
	int &ret = dp[idx];
	if(ret != -1) return ret;
	
	ret = 0;
	
	if(cnt[idx]) ret += go(idx+1);
	else if(!cnt[idx+1]) ret += (go(idx+1) + go(idx+2));
	else ret += go(idx+1);
	
	return ret;
}
int main(){
	cin >> n >> m;
	memset(dp, -1, sizeof(dp));
	for(int i = 0; i < m; i++){
		cin >> temp;
		cnt[temp - 1] = 1;
	}
	cout << go(0) << "\n";
	return 0;
}