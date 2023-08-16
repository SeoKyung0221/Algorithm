#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000000;
int n;
ll dp[104][10], ret;

ll go(int idx, int num){
	if(idx == n) return 1;
	if(num < 0 || num > 9) return 0;
	
	ll &ret = dp[idx][num];
	if(ret != 0) return ret;
	
	ret = 0;
	if(num == 0){
		ret = go(idx + 1, num + 1);
		ret %= mod;
	}
	else if(num == 9){
		ret = go(idx + 1, num - 1);
		ret %= mod; 
	}
	else{
		ret = go(idx + 1, num - 1) + go(idx + 1, num + 1);	
		ret %= mod;
	}
	ret %= mod;
	return ret;
}
int main(){
	cin >> n;
	ll ret = 0;
	for(int i = 1; i <= 9; i++){
		ret += go(1, i);
		ret %= mod;
	}
	cout << ret << "\n";
}