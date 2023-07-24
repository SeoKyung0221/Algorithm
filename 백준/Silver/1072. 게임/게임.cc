#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll x, y, ret = -1;

int main(){
	cin >> x >> y;
	ll z = y * 100 / x;
	ll l = 1; ll h = 1e9;
	while(l <= h){
		ll mid = (l+h) / 2;
		if(z < (y+mid) * 100 / (x+mid)){
			h = mid - 1;
			ret = mid;
		}else l = mid + 1;
	}
	cout << ret << "\n";
}