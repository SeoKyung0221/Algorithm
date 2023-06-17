#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll maxHP, CurHP, atk, n, q, w, e;
ll ret;
struct Dun{
	ll t;
	ll a;
	ll h;
};
vector<Dun> N;
bool go(ll CurHP){
	for(int i = 0; i < n; i++){
		if(N[i].t == 1){
			if(N[i].h % atk != 0){
				ll k = N[i].h / atk;
				CurHP -= k * N[i].a;
			} else{
				ll k = (N[i].h / atk) - 1;
				CurHP -= k * N[i].a;
			}
			if(CurHP <= 0){
				return false;
			}
		}
		else if(N[i].t == 2){
			atk += N[i].a;
			CurHP += N[i].h;
			if(CurHP > maxHP) CurHP = maxHP;
		}
	}
	return true;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> atk;
	for(int i = 0; i < n; i++){
		cin >> q >> w >> e;
		N.push_back({q, w, e});
	}
	ll l = 1, h = 1e18 + 4;
	ll atk_ = atk;
	ll curHP = 0;
	while(l <= h){
		maxHP = (l+h) / 2;
		CurHP = (l+h) / 2;
		atk = atk_;
		if(go(CurHP)){
			h = CurHP - 1;
			ret = CurHP;
		}
		else l = CurHP + 1;
	}
	cout << ret << "\n";
}