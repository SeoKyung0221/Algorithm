#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, k, m, v, c, ret;
vector<pair<ll, ll>> v1;
vector<ll> v2;

int main(){
	cin >> n >> k;
	for(int i = 0; i < n; i++){
		cin >> m >> v;
		v1.push_back({m, v});
	}
	for(int i = 0; i < k; i++){
		cin >> c;
		v2.push_back(c);
	}
	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());
	priority_queue<ll> pq;
	int j = 0;
	
	for(int i = 0; i < k; i++){
		while(j < n && v1[j].first <= v2[i]){
			pq.push(v1[j++].second);
		}
		if(pq.size()){
			ret += pq.top(); pq.pop();
		}
	}
	cout << ret << "\n";
}