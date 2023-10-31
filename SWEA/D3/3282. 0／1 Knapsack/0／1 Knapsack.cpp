#include<bits/stdc++.h>
using namespace std;
int te, tcnt, n, k, a, b, dp[1004][104];
vector<pair<int,int>> v;
int solve(int w, int idx){
	if(idx == n) return 0;
	
	int &ret = dp[w][idx];
	if(ret != -1) return ret;
	
	ret = 0;
	
	ret = max(ret, solve(w, idx + 1));
	if(w + v[idx].first <= k) ret = max(ret, v[idx].second + solve(w + v[idx].first, idx+1));
	
	return ret;
}
int main(){
	cin >> te;
	while(te--){
		tcnt++;
		v.clear();
		memset(dp, -1, sizeof(dp));
		
		cin >> n >> k;
		for(int i = 0; i < n; i++){
			cin >> a >> b;
			v.push_back({a, b});
		}
		sort(v.begin(), v.end());
		
		cout << "#" << tcnt << " " << solve(0,0) << "\n";
	}
    return 0;
}