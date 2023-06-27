#include<bits/stdc++.h>
using namespace std;
int n, l[24], j[24], dp[104];

int main(){
	memset(dp,0,sizeof(dp));
	cin >> n;
	for(int i = 0; i < n ; i++){
		cin >> l[i];
	}
	for(int i = 0; i < n; i++){
		cin >> j[i];
	}
	for(int i = 0; i < n; i++){
		for(int k = 100; k >= l[i]; k--){
			if(k-l[i] == 0) continue;
			dp[k] = max(dp[k], dp[k-l[i]] + j[i]);
		}
	}
	cout << dp[100] << "\n";
}