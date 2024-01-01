#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, m, a[300004], ret = 1e9;

bool check(ll mid){
	ll temp = 0;
	for(int i = 0; i < m; i++){
		if(a[i] % mid == 0){
			temp += a[i] / mid;
		}else{
			temp += (a[i] / mid) + 1;
		}
	}
	return n >= temp;
}
int main(){
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		cin >> a[i];
	}
	ll l = 1, h = 1e9;
	while(l <= h){
		ll mid = (l + h) / 2;
		if(check(mid)){
			ret = mid;
			h = mid - 1;
		}else{
			l = mid + 1;
		}
	}
	cout << ret << "\n";
	return 0;
}