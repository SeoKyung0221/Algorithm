#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 60000000004;
ll n, m, l, h = INF, a[10004], ret;

bool check(ll mid){
	ll temp = m;
	for(int i = 0; i < m; i++){
		temp += mid / a[i];
	}
	return temp >= n;
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
	while(l <= h){
		ll mid = (l + h) / 2;
		if(check(mid)){
			ret = mid;
			h = mid - 1;
		}else{
			l = mid + 1;
		}
	}
	ll temp = m;
	for(int i = 0; i < m; i++){
		temp += (ret-1) / a[i];
	}
	for(ll i = 0; i < m; i++){
		if(ret % a[i] == 0) temp++;
		if(temp == n){
			cout << i + 1 << "\n";
			return 0;
		}
	}
	return 0;
}