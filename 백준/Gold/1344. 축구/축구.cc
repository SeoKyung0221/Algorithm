#include<bits/stdc++.h>
using namespace std;
double a, b, dp[20][20][20];
bool che[20];

void era(){
	for(int i = 2; i <= 20; i++){
		if(che[i]) continue;
		for(int j = 2 * i; j <= 20; j += i){
			che[j] = 1;
		}
	}
	for(int i = 2; i <= 20; i++){
		if(che[i] == 1) che[i] = 0;
		else che[i] = 1;
	}
	return;
}
double solve(int idx, int A_, int B_){
	if(idx == 18) return che[A_] || che[B_] ? 1.0 : 0.0;
	
	double &ret = dp[idx][A_][B_];
	if(ret > -0.5) return ret;
	
	ret = 0.0;
	ret += solve(idx+1, A_, B_) * (1-a) * (1-b);
	ret += solve(idx+1, A_ + 1, B_) * a * (1-b);
	ret += solve(idx+1, A_, B_ + 1) * (1-a) * b;
	ret += solve(idx+1, A_ + 1, B_ + 1) * a * b;
	
	return ret;
}
int main(){
	fill(&dp[0][0][0], &dp[0][0][0] + 20 * 20 * 20, -1);
	cin >> a >> b;
	a /= 100;
	b /= 100;
	era();
	printf("%0.6lf", solve(0, 0, 0));
}