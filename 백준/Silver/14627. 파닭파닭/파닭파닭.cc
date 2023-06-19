#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll s, c, a, ret;
vector<ll> v;

bool check(ll mid){
	ll cnt = 0;
	for(int i = 0; i < s; i++){
		cnt += v[i] / mid;
	}
	return cnt >= c;
}

int main(){
	ll sum = 0;
	cin >> s >> c;
	for(int i = 0; i < s; i++){
		cin >> a;
		v.push_back(a);
		sum += a;
	}
	sort(v.begin(), v.end());
	
	ll lo = 1, hi = 1e9;
	ll mid;
	while(lo <= hi){
		mid = (lo+hi) / (1LL * 2);
		if(check(mid)){
			lo = mid + 1;
			ret = mid;
		} else{
			hi = mid - 1;
		}
	}
	cout << sum - ret*c << "\n";
}