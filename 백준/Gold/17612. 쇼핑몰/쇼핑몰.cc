#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, k, a, b, ret;
struct A{
	ll id, _time, cashe;
}; 
struct cmp{
	bool operator()(A a, A b){
		if(a._time == b._time) return a.cashe > b.cashe;
		else return a._time > b._time;
	}
};
priority_queue<A, vector<A>, cmp> pq;
vector<A> v;

bool cmp2(A a, A b){
	if(a._time == b._time) return a.cashe > b.cashe;
	else return a._time < b._time;
}

int main(){
	cin >> n >> k;
	for(int i = 1; i <= n; i++){
		cin >> a >> b;
		if(i <= k){
			pq.push({a, b, i});
		}else{
			v.push_back(pq.top());
			ll temp_time, temp_cashe;
			temp_time = pq.top()._time, temp_cashe = pq.top().cashe;
			pq.pop();
			pq.push({a, temp_time + b, temp_cashe});
		}
	}
	while(pq.size()){
		v.push_back(pq.top());
		pq.pop();
	}
	sort(v.begin(), v.end(), cmp2);
	for(ll i = 1; i <= v.size(); i++){
		ret += i * v[i-1].id;
	}
	cout << ret << "\n";
}
