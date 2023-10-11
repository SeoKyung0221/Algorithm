#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, k, dp[104][100004], p, q;
vector<pair<ll,ll>> a, b;

ll solve(ll cnt, ll time){
	if(time > k) return -1e18;
	if(cnt >= n) return 0;
	
	ll ret = dp[cnt][time];
	if(ret != -1) return ret;
	
	ret = 0;
	ll left = solve(cnt + 1, time + a[cnt].first) + a[cnt].second;
	ll right = solve(cnt + 1, time + b[cnt].first) + b[cnt].second;
	
	ret = max(left, right);
	
	return ret;
}
int main(){
	memset(dp, -1, sizeof(dp));
	cin >> n >> k;
	for(int i = 0; i < n; i++){
		cin >> p >> q;
		a.push_back({p,q});
		cin >> p >> q;
		b.push_back({p,q});
	}
	cout << solve(0, 0) << "\n";
	return 0;
}