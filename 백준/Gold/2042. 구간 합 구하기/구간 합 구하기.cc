#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, m, k, a, b, c, f[1000004];

ll sum(vector<ll> &tree, ll i){
	ll ans = 0;
	while(i > 0){
		ans += tree[i];
		i -= (i & -i);
	}
	return ans;
}
void update(vector<ll> &tree, ll i , ll diff){
	while(i <= n){
		tree[i] += diff;
		i += (i & -i);
	}
	return;
}
int main(){
	cin >> n >> m >> k;
	vector<ll> tree(n+1);
	for(ll i = 1; i <= n; i++){
		cin >> f[i];
		update(tree, i, f[i]);
	}
	for(ll i = 0; i < m+k; i++){
		cin >> a;
		if(a == 1){
			cin >> b >> c;
			update(tree, b, c-f[b]);
			f[b] = c;
		}else{
			cin >> b >> c;
			cout << sum(tree, c) - sum(tree, b-1) << "\n";
		}
	}
}