#include<bits/stdc++.h>
using namespace std;
int n, dp[1000004];

int go(int x){
	if(x == 1) return 0;
	
	int &ret = dp[x];
	if(ret != 1e9) return ret;
	
	ret = go(x - 1) + 1;
	if(x % 2 == 0) ret = min(ret, go(x / 2) + 1);
	if(x % 3 == 0) ret = min(ret, go(x / 3) + 1);
	
	return ret;
}
int main(){
	fill(dp, dp + 1000004, 1e9);
	cin >> n;
	
	cout << go(n) << "\n";
}