#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll t, n, m, k;

int main(){
	cin >> t;
	while(t--){
		ll ret = 0;
		vector<int> a, b;
		cin >> n >> m;
		for(int i = 0; i < n; i++){
			cin >> k;
			a.push_back(k);
		}
		for(int i = 0; i < m; i++){
			cin >> k;
			b.push_back(k);
		}
		
		sort(b.begin(), b.end());

		for(int i : a){
			ll low = 0; ll hi = m-1;
			while(low <= hi){
				ll mid = (low+hi) / 2;
				if(i > b[mid]){
					ret += (mid-low)+1;
					low = mid+1;
				} else if(i <= b[mid]){
					hi = mid - 1;
				}
			}
		}
		cout << ret << "\n";
	}
}