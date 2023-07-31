#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9 + 7;
const int MAX_N = 200004;
int n, value;
ll ret = 1;

ll sum(vector<ll> &tree, int i){
    ll ans = 0;
    while(i > 0){
        ans += tree[i];
        i -= (i & -i);
    }
    return ans;
}

ll _sum(vector<ll> &tree, int s, int e){
    if(s > e) return 0;
    return sum(tree, e) - sum(tree, s-1);
}
void update(vector<ll> &tree, int i, int value){
    while(i < tree.size()){
        tree[i] += value;
        i += (i & -i);
    }
    return;
}
int main(){
    cin >> n;
    vector<ll> tree_cnt(MAX_N, 0);
    vector<ll> tree(MAX_N, 0);
    for(int i = 1; i <= n; i++){
        cin >> value; value++;
        if(i != 1){
            ll l = value * _sum(tree_cnt, 1, value - 1) - _sum(tree, 1, value - 1);
            ll r = _sum(tree, value + 1, MAX_N) - value * _sum(tree_cnt, value + 1, MAX_N);
            ret *= (l + r) % mod;
            ret %= mod;
        }
        update(tree_cnt, value, 1);
        update(tree, value, value);
    }
    cout << ret << "\n";
}
