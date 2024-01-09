#include<bits/stdc++.h>
using namespace std;
int n, w, a, b, dp[1004][1004];
vector<pair<int, int>> v;

int cal(int a, int b){
	return abs(v[a].first - v[b].first) + abs(v[a].second - v[b].second);
}
int solve(int one, int two){
	if(one == w + 1 || two == w + 1){
		return 0;
	}
	
	int &ret = dp[one][two];
	if(ret != -1) return ret;
	
	ret = 1e9;
	int next = max(one, two) + 1;
	ret = min(ret, solve(next, two) + cal(one, next));
	ret = min(ret, solve(one, next) + cal(two, next));
	
	return ret;
}
int main(){
	memset(dp, -1, sizeof(dp));
	cin >> n >> w;
	v.push_back({1, 1});
	v.push_back({n, n});
	for(int i = 2; i < w + 2; i++){
		cin >> a >> b;
		v.push_back({a, b});
	}
	cout << solve(0, 1) << "\n";
	int a = 0, b = 1;
	for(int i = 2; i < w + 2; i++){
		if(dp[i][b] + cal(i, a) < dp[a][i] + cal(b, i)){
			cout << "1\n";
			a = i;
		}else{
			cout << "2\n";
			b = i;
		}
	}
}