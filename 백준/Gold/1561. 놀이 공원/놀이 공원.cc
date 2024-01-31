#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, m, a[10004], _time;

bool check(ll mid){
	ll temp = m;
	
	for(int i = 0; i < m; i++){
		temp += (mid / a[i]);
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
	ll l = 1, h = 6 * 1e10;
	while(l <= h){
		ll mid = (l + h) / 2;
		if(check(mid)){
			_time = mid;
			h = mid - 1;
		}else{
			l = mid + 1;
		}
	}
	ll temp = m;
	for(int i = 0; i < m; i++){
		temp += (_time - 1) / a[i];
	}
	for(int i = 0; i < m; i++){
		if(_time % a[i] == 0) temp++;
		if(temp == n){
			cout << i + 1 << "\n";
			break;
		}
	}
}