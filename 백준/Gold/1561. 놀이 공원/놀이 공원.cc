#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, m, a[10004], temp;

bool check(ll mid){
	ll ret = m;
	for(int i = 0; i < m; i++){
		ret += mid / a[i];
	}
	return ret >= n;
}
int main(){
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		cin >> a[i];
	}
	if(n <= m){
		cout << n << "\n";
		return 0;
	}
	
	ll l = 1, h = 6 * 1e10;
	while(l <= h){
		ll mid = (l + h) / 2;
		if(check(mid)){
			temp = mid;
			h = mid - 1;
		}else{
			l = mid + 1;
		}
	}
	ll ret = m;
	for(int i = 0; i < m; i++){
		ret += (temp - 1) / a[i];
	}
	for(int i = 0; i < m; i++){
		if(temp % a[i] == 0) ret++;
		if(ret == n){
			cout << i + 1 << "\n";
			return 0;
		}
	}
	return 0;
}