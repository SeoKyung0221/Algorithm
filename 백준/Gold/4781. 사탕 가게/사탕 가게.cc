#include<bits/stdc++.h>
using namespace std;
int n, c, a, m, b, p, ret, dp[10004];

int main(){
	while(true){
		fill(dp, dp + 10004, 0);
		scanf("%d %d.%d", &n, &a, &m);
		int k = a * 100 + m;
		if(n == 0 && a == 0 && m == 0) break;
		for(int i = 0; i < n; i++){
			scanf("%d %d.%d", &c, &b, &p);
			int q = b * 100 + p;
			for(int j = q; j <= k; j++){
				dp[j] = max(dp[j], dp[j-q] + c);
			}
		}
		printf("%d\n", dp[k]);
	}
}