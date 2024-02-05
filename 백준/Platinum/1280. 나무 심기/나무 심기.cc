#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;
ll n, num, ret = 1;

ll sum(vector<ll> &tree, int i){
	ll ret = 0;
	
	while(i > 0){
		ret += tree[i];
		i -= (i & -i);
	}
	return ret;
}

void update(vector<ll> &tree, int i, ll diff){
	while(i < tree.size()){
		tree[i] += diff;
		i += (i & -i);
	}
	return;
}

ll _sum(vector<ll> &tree, int s, int e){
	return sum(tree, e) - sum(tree, s - 1);
}

int main(){
	cin >> n;
	
	vector<ll> tree_cnt(200004, 0);
	vector<ll> tree(200004, 0);
	for(int i = 1; i <= n; i++){
		cin >> num; num++;
		
		if(i != 1){
			ll left = (_sum(tree_cnt, 1, num - 1) * num - _sum(tree, 1, num - 1)) % mod;
			ll right = (_sum(tree, num + 1, 200004) - _sum(tree_cnt, num + 1, 200004) * num) % mod;
			ret *= (left + right) % mod;
			ret %= mod;
		}
		
		update(tree_cnt, num, 1);
		update(tree, num, num);
	}
	cout << ret << "\n";
}