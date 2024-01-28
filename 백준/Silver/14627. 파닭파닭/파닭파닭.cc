#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll s, c, l, a[1000004], mx, sum, temp;

bool check(ll mid){
	ll ret = 0;
	
	for(int i = 0; i < s; i++){
		ret += (a[i] / mid);
	}
	return ret >= c;
}

int main(){
	cin >> s >> c;
	for(int i = 0; i < s; i++){
		cin >> a[i];
		mx = max(a[i], mx);
		sum += a[i];
	}
	ll l = 1, h = mx;
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