#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, a[104], dp[104][24];

ll go(int idx, int cnt){
	if(cnt > 20 || cnt < 0) return 0;
	
	ll &ret = dp[idx][cnt];
	if(ret) return ret;
	
	if(idx == n-1){
		if(cnt == a[n-1]) return 1;
		return 0;
	}

	ret += go(idx + 1, cnt + a[idx]);
	ret += go(idx + 1, cnt - a[idx]);
	
	return ret;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	cout << go(1, a[0]) << "\n";
}