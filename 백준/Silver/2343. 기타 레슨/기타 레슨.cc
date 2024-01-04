#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, m, a[100004], mx, ret;

bool check(ll mid){
	ll ans = 1;
	ll temp = mid;
	for(int i = 0; i < n; i++){
		if(temp >= a[i]){
			temp -= a[i];
		}else{
			ans++;
			temp = mid;
			temp -= a[i];
		}
	}
	return ans <= m;
}
int main(){
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		cin >> a[i];
		mx = max(mx, a[i]);
	}
	ll l = mx, h = 1e9;
	while(l <= h){
		ll mid = (l + h) / 2;
		if(check(mid)){
			ret = mid;
			h = mid -1;
		}else{
			l = mid + 1;
		}
	}
	cout << ret << "\n";
}