#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 15746;
int n;
ll dp[1000004];

ll solve(int size){
	if(size == 1) return 1;
	if(size == 2) return 2;
	
	ll &ret = dp[size];
	if(ret != 0) return ret; 
	
	ret = 0;
	ret += solve(size - 2) + solve(size - 1);
	ret %= mod;
	
	return ret;
}

int main(){
	cin >> n;
	cout << solve(n) << "\n";
}