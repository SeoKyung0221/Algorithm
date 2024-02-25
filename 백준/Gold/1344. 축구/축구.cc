#include<bits/stdc++.h>
using namespace std;
double a, b, dp[19][19][19];

bool check(int n){
	if(n <= 1) return 0;
	if(n == 2) return 1;
	if(n % 2 == 0) return 0;
	for(int i = 2; i * i <= n; i++){
		if(n % i == 0) return 0;
	}
	return 1;
}
double solve(int idx, int p, int q){
	if(idx == 18){
		if(check(p) || check(q)) return 1.0;
		else return 0.0;
	}
	
	double &ret = dp[idx][p][q];
	if(ret > -1) return ret;
	
	ret = 0.0;
	ret += solve(idx + 1, p, q) * (1 - a) * (1 - b);
	ret += solve(idx + 1, p + 1, q) * a * (1 - b);
	ret += solve(idx + 1, p, q + 1) * (1 - a) * b;
	ret += solve(idx + 1, p + 1, q + 1) * a * b;
	
	return ret;
}
int main(){
	memset(dp, -1.0, sizeof(dp));
	cin >> a >> b;
	a = a / 100, b = b / 100;
	
	printf("%0.6lf", solve(0, 0, 0));
}