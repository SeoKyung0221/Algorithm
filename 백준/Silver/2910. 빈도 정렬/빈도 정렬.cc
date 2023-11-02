#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, c, num;
map<ll, int> mp, mp_first;
vector<pair<int, ll>> v;

bool cmp(pair<int, ll> a, pair<int, ll> b){
	if(a.first == b.first){
		return mp_first[a.second] < mp_first[b.second];
	}else return a.first > b.first;
}
int main(){
	cin >> n >> c;
	for(int i = 0; i < n; i++){
		cin >> num;
		mp[num]++;
		if(mp_first[num] == 0) mp_first[num] = i + 1;
	}
	for(auto it : mp){
		v.push_back({it.second, it.first});
	}
	sort(v.begin(), v.end(), cmp);
	for(auto i : v){
		for(int j = 0; j < i.first; j++){
			cout << i.second << " ";
		}
	}
}