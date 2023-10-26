#include<bits/stdc++.h>
using namespace std;
int te, tcnt, n, l, t, k;
vector<pair<int,int>> v;

int main(){
	cin >> te;
	while(te--){
		v.clear();
		int ret = 0;
		tcnt++;
		
		cin >> n >> l;
		
		for(int i = 0; i < n; i++){
			cin >> t >> k;
			v.push_back({t, k});
		}
		for(int i = 0; i < (1 << n); i++){
			t = 0, k = 0;
			for(int j = 0; j < n; j++){
				if(i & (1 << j)){
					t += v[j].first;
					k += v[j].second;
				}
			}
			if(k <= l){
				ret = max(ret, t);
			}
		}
		cout << "#" << tcnt << " " << ret << "\n";
	}
}