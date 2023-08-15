#include<bits/stdc++.h>
using namespace std;
int x, dp[1000004];

int go(int idx){
	if(idx == 1) return 0;
	
	int &ret = dp[idx];
	if(ret != 1e9) return ret;
	
	ret = go(idx-1) + 1;
	if(idx % 2 == 0) ret = min(ret, go(idx / 2) + 1);
	if(idx % 3 == 0) ret = min(ret, go(idx / 3) + 1);
	
	return ret;
}
int main(){
	fill(dp, dp + 1000004, 1e9);
	cin >> x;
	
	cout << go(x) << "\n";
}