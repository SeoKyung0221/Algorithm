#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1000000000;
ll n, dp[10][104];

ll go(int num, int idx){
	if(idx == n) return 1;
	
	ll &ret = dp[num][idx];
	if(ret != 0) return ret;
	
	if(num == 0) ret += go(num + 1, idx + 1);
	else if(num == 9) ret += go(num - 1, idx + 1);
	else{
		ret += go(num - 1, idx + 1) + go(num + 1, idx + 1);
	}
	ret %= mod;
	
	return ret;
}
int main(){
	cin >> n;
	ll cnt = 0;
	for(int i = 1; i <= 9; i++){
		cnt += go(i, 1);
		cnt %= mod;
	}
	cout << cnt << "\n";
}