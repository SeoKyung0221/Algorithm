#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MAX_N = 1e9;
ll x, y, z, ret = -1;
int main(){
	cin >> x >> y;
	z = y * 100 / x;
	
	ll l = 1, h = MAX_N;
	while(l <= h){
		ll mid = (l+h) / 2;
		if(z < ((y + mid) * 100 / (x+mid))){
			ret = mid;
			h = mid - 1;
		}
		else{
			l = mid + 1;
		}
	}
 	cout << ret << "\n";
}