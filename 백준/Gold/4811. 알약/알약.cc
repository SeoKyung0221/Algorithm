#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, dp[34][68]; // 전체알, 반알 

ll go(int one, int half){
	if(one == 0 && half == 0){
		return 1;
	}
	if(one == 0) return go(one, half - 1);
	if(half == 0) return go(one - 1, half + 1);
	
	ll &ret = dp[one][half];
	if(ret != -1) return ret;
	
	ret = 0;
	
	return ret = go(one - 1, half + 1) + go(one, half - 1);
}
int main(){
	while(true){
		memset(dp, -1, sizeof(dp));
		cin >> n;
		if(n == 0) return 0;
		
		cout << go(n, 0) << "\n"; 
	}
}