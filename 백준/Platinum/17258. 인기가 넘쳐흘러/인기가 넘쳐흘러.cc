#include<bits/stdc++.h>
using namespace std;
int n, m, k, t, a, b, cnt[304], dp[304][304];
vector<pair<int, int>> v;

int solve(int idx, int num, int prev){
	if(idx == v.size()) return 0;
	int &ret = dp[idx][num];
	if(ret != -1) return ret;
	
	ret = 0;
	
	int cost = max(0, t - v[idx].second);
	int real_cost = (prev >= cost) ? 0 : cost - prev;
	
	if(num - real_cost >= 0){
		ret = max(solve(idx + 1, num - real_cost, cost) + v[idx].first, solve(idx + 1, num, 0));
	}else{
		ret = max(ret, solve(idx + 1, num, 0));
	}
	return ret;
}
int main(){
	memset(dp, -1, sizeof(dp));
	cin >> n >> m >> k >> t;
	for(int i = 0; i < m; i++){
		cin >> a >> b;
		for(int j = a; j < b; j++){
			cnt[j] = min(t, ++cnt[j]);
		}
	}
	int _cnt = 1;
	int temp = cnt[1];
	for(int i = 2; i <= n; i++){
		if(temp != cnt[i]){
			v.push_back({_cnt, temp});
			temp = cnt[i];
			_cnt = 0;
		}
		_cnt++;
	}
	v.push_back({_cnt, temp});
	
	cout << solve(0, k, 0) << "\n";
}