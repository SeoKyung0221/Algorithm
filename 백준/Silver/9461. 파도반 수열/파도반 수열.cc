#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int t, n;
ll dp[104];

ll go(int n){
	if(n == 1 || n == 2 || n == 3) return 1;
	if(n == 4 || n == 5) return 2;
	if(n == 6) return 3;
	if(n == 7) return 4;
	if(n == 8) return 5;
	if(n == 9) return 7;
	if(n == 10) return 9;
	
	ll &ret = dp[n];
	if(ret != 0) return ret;
	
	ret = go(n - 5) + go(n - 1);
	
	return ret;
}
int main(){
	cin >> t;
	for(int p = 0; p < t; p++){
		cin >> n;
		cout << go(n) << "\n";
	}
}