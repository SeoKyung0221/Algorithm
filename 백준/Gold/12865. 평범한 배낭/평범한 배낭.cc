#include<bits/stdc++.h>
using namespace std;
int n, k, dp[100004], w, v;

int main(){
	cin >> n >> k;
	for(int i = 0; i < n; i++){
		cin >> w >> v;
		if(w > k) continue;
		for(int j = k; j >= w; j--){
			dp[j] = max(dp[j], dp[j-w] + v);
		}
	}
	cout << dp[k] << "\n";
}