#include<bits/stdc++.h>
using namespace std;
int n, t, p, dp[21];
pair<int, int> a[16];

int go(int idx){
	if(idx == n) return 0;
	
	int &ret = dp[idx];
	if(ret != 0) return ret;
	
	if(idx + a[idx].first <= n) ret = max(ret, go(idx + a[idx].first) + a[idx].second);
	ret = max(ret, go(idx + 1));
	
	return ret;
}
int main(){
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> t >> p;
		a[i] = {t, p};
	}
	cout << go(0) << "\n";
	return 0;
}