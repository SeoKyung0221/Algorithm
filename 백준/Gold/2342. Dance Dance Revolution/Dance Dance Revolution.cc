#include<bits/stdc++.h>
using namespace std;
int n, num, dp[5][5][100004];
vector<int> v;

int check(int here, int next){
	if(here == 0) return 2;
	else if(here == next) return 1;
	else if(abs(here - next) == 2) return 4;
	else return 3;
}
int solve(int l, int r, int cnt){
	if(cnt == n) return 0;
	
	int &ret = dp[l][r][cnt];
	if(ret != -1) return ret;
	
	int left = solve(v[cnt], r, cnt+1) + check(l, v[cnt]);
	int right = solve(l, v[cnt], cnt+1) + check(r, v[cnt]);
	
	ret = min(left, right);
	
	return ret;
}
int main(){
	memset(dp, -1, sizeof(dp));
	while(true){
		cin >> num;
		if(num == 0) break;
		v.push_back(num);
	}
	n = v.size();
	cout << solve(0, 0, 0) << "\n";	
	return 0;
}