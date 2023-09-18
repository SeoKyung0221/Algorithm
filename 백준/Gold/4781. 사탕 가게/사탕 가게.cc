#include<bits/stdc++.h>
using namespace std;
int n, m, l, c, p, o, dp[11000];

int main(){
	while(true){
		fill(dp, dp + 11000, 0);
		scanf("%d %d.%d", &n, &m, &l);
		if(n == 0 && m == 0 && l == 00) break;
		int a = 100 * m + l;
		for(int i = 0; i < n; i++){
			scanf("%d %d.%d", &c, &p, &o);
			int b = 100 * p + o;
			for(int j = b; j <= a; j++){
				dp[j] = max(dp[j], dp[j-b] + c);
			}
		}
		cout << dp[a] << "\n";
	}
}