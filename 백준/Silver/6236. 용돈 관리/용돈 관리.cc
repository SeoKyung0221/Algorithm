#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, m, a[100004], mx, ret;

bool check(ll mid){
	ll temp = 1;
	ll now = mid;
	for(int i = 0; i < n; i++){
		if(a[i] > now){
			temp++;
			now = mid;
			now -= a[i];
		}else{
			now -= a[i];
		}
	}
	return temp <= m;
}
int main(){
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		cin >> a[i];
		mx = max(a[i], mx);
	}
	ll l = mx, h = 1e9;
	while(l <= h){
		ll mid = (l + h) / 2;
		if(check(mid)){
			ret = mid;
			h = mid - 1;
		}else l = mid + 1;
	}
	cout << ret << "\n";
}