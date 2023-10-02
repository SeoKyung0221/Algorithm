#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, m, a[10004], l, h = 60000000004, temp, ret;

bool check(ll mid){
	temp = m;
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
		cout << n;
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
	temp = m;
	for(int i = 0; i < m; i++){
		temp += (ret - 1) / a[i];
	}
	for(ll i = 0; i < m; i++){
		if(ret % a[i] == 0) temp++;
		if(temp == n){
			cout << i + 1 << "\n";
			return 0;
		}
	}
}