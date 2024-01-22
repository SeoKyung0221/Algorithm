#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll te, n, m, num;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> te;
	while(te--){
		cin >> n;
		vector<int> v;
		for(int i = 0; i < n; i++){
			cin >> num;
			v.push_back(num);
		}
		sort(v.begin(), v.end());
		cin >> m;
		for(int i = 0; i < m; i++){
			cin >> num;
			int flag = 0;
			ll l = 0, h = n-1;
			while(l <= h){
				ll mid = (l + h) / 2;
				if(v[mid] > num){
					h = mid - 1;
				}else if(v[mid] < num){
					l = mid + 1;
				}else if(v[mid] == num){
					flag = 1;
					break;
				}
			}
			if(flag) cout << "1\n";
			else cout << "0\n";
		}
	}
}