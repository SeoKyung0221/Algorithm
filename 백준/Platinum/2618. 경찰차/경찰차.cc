#include<bits/stdc++.h>
using namespace std;
int n, w, p, q, dp[1004][1004];
pair<int, int> a[1004];

int dist(int p, int q){
	return abs(a[p].first - a[q].first) + abs(a[p].second - a[q].second);
}
int go(int one, int two){
	if(one == w + 2 || two == w + 2){
		return 0;
	}
	int &ret = dp[one][two];
	if(ret != -1) return ret;
	
	ret = 0;
	int next = max(one, two) + 1;
	
	ret = min(go(next, two) + dist(one, next), go(one, next) + dist(two, next));
	
	return ret;
}
int main(){
	cin >> n >> w;
	memset(dp, -1, sizeof(dp));
	a[1].first = 1, a[1].second = 1;
	a[2].first = n, a[2].second = n;
	for(int i = 3; i <= w + 2; i++){
		cin >> p >> q;
		a[i].first = p, a[i].second = q;
	}
	cout << go(1, 2) << "\n";
	
	int one = 1;
	int two = 2;
	for(int i = 3; i <= w + 2; i++){
		if(dp[i][two] + dist(one, i) > dp[one][i] + dist(two, i)){
			two = i;
			cout << 2 << "\n";
		}else{
			one = i;
			cout << 1 << "\n";
		}
	}
}