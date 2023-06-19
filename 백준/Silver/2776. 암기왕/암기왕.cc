#include<bits/stdc++.h>
using namespace std;
int t, n, m, a, b;
vector<int> v1;
vector<int> v2;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> t;
	while(t--){
		v1.clear();
		v2.clear();
		cin >> n;
		for(int i = 0; i < n; i++){
			cin >> a;
			v1.push_back(a);
		}
		cin >> m;
		for(int i = 0; i < m; i++){
			cin >> b;
			v2.push_back(b);
		}
		sort(v1.begin(), v1.end());

		for(int i = 0; i < m; i++){
			int lo = 0, hi = n-1;
			int mid;
			int ret = 0;
			while(lo <= hi){
				mid = (lo + hi) / 2;
				if(v2[i] < v1[mid]){
					hi = mid - 1;
				} else if(v2[i] > v1[mid]){
					lo = mid + 1;
				} else if(v2[i] == v1[mid]){
					ret = 1;
					break;
				}
			}
			cout << ret << "\n";
		}
	}
}