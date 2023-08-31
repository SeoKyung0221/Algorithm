#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, m, mx, a[100004], ret = 1e9;

bool check(ll mid){
	if(mid < mx) return false;
	ll temp = mid;
	ll cnt = 1;
	for(int i = 0; i < n; i++){
		if(temp - a[i] < 0){
			cnt++;
			temp = mid;
			temp -= a[i];
		}else temp -= a[i];
	}
	return cnt <= m;
}
int main(){
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		cin >> a[i];
		mx = max(mx, a[i]);
	}
	ll l = 0, h = 1e9;
	while(l <= h){
		ll mid = (l + h) / 2;
		if(check(mid)){
			ret = min(ret, mid);
			h = mid - 1;			
		}else l = mid + 1;
	}
	cout << ret << "\n";
}