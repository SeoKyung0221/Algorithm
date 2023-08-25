#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, m, a[100004], mx, ret = 1e9;

bool check(ll mid){
	if(mx > mid) return false;
	ll cnt = 1;
	ll temp = mid;
	for(int i = 0; i < n; i++){
		if(mid - a[i] < 0){
			mid = temp;
			cnt++;
			mid -= a[i];
		}
		else mid -= a[i];
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
			h = mid - 1;
			ret = min(ret, mid);
		}else{
			l = mid + 1;
		}
	}
	cout << ret << "\n";
}