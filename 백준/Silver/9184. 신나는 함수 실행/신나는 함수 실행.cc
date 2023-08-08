#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dp[54][54][54];
int a, b, c;

ll solve(int a, int b, int c){
	if(a <= 0 || b <= 0 || c <= 0) return 1;
	if(a > 20 || b > 20 || c > 20) return solve(20, 20, 20);
	
	ll &ret = dp[a][b][c];
	if(ret != 0) return ret;
	
	if(a < b && b < c){
		ret = solve(a, b, c - 1) + solve(a, b-1, c-1) - solve(a, b-1, c);
	}else{
		ret = solve(a-1, b, c) + solve(a-1, b-1, c) + solve(a-1, b, c-1) - solve(a-1, b-1, c-1);
	}
	return ret;
}
int main(){
	while(true){
		cin >> a >> b >> c;
		if(a == -1 && b == -1 && c == -1) break;
		printf("w(%d, %d, %d) = %d\n", a, b, c, solve(a, b, c));
	}
}