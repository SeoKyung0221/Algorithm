#include<bits/stdc++.h>
using namespace std;
typedef long long ll ;
ll n, m, a[300004], ret = 1e18;

bool check(int mid){
	ll num = 0;
	for(int i = 0; i < m; i++){
		num += a[i] / mid;
		if(a[i] % mid) num++;
	}
	return n >= num;
}
int main(){
	cin >> n >> m;
	ll l = 1, r = 0, mid;
	for(int i = 0; i < m; i++){
		cin >> a[i];
		r = max(r, a[i]);
	}
	while(l <= r){
		mid = (l+r) / 2;
		if(check(mid)){
			ret = min(ret, mid);
			r = mid - 1;
		}
		else l = mid + 1;
	}
	cout << ret << "\n";
}