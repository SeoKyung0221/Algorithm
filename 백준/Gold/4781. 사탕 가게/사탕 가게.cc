#include<bits/stdc++.h>
using namespace std;
int n, c, a, b, d, e, dp[10004];

int main(){
	while(true){
		fill(dp, dp + 10004, 0);
		scanf("%d %d.%d", &n , &a, &b);
		int p = a * 100 + b;
		if(n == 0 && a == 0 && b == 00) break;
		for(int i = 0; i < n; i++){
			scanf("%d %d.%d", &c, &d, &e);
			int q = d * 100 + e;
			for(int j = q; j <= p; j++){
				dp[j] = max(dp[j], dp[j - q] + c);
			}
		}
		cout << dp[p] << "\n"; 
	}
}