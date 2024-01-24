#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll s, c, a[1000004], sum, temp, ret;

bool check(ll mid){
	ll cnt = 0;
	
	for(int i = 0; i < s; i++){
		cnt += (a[i] / mid);
	}
	
	return cnt >= c;
}
int main(){
	cin >> s >> c;
	for(int i = 0; i < s; i++){
		cin >> a[i];
		sum += a[i];
	}
	ll l = 1, h = 1e9;
	while(l <= h){
		ll mid = (l + h) / 2;
		if(check(mid)){
			temp = mid;
			l = mid + 1;
		}else{
			h = mid - 1;
		}
	}
	cout << sum - temp * c << "\n";
}