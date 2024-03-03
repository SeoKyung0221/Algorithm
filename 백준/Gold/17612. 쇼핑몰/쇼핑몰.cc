/*
1. 시간이 같을 경우에는 가장 번호가 작은 계산대로! (즉, 시간이 가장 적은 곳으로 간다)
2. 고객이 동일하게 계산을 마쳤다면 높은 번호의 계산대순서대로 나간다. 
3. 구하는건 쇼핑몰에 빠져나간 순서대로 구해야한다. 
4. n은 고객, k가 계산대이다. 

쇼핑몰에 각 계산대마다 손님들이 들어간다. 그때 손님의 번호를 당연히 저장해야겠지? (1)
그리고 손님이 할애하는 시간도 저장해야겠지(2) -> 그런데! 여기서 손님의 시간같은 경우에는 계산대 우선순위를 결정하기
때문에 잘 계산해야함.
그리고 당연히 각 계산대마다의 번호도 저장해야 할 것이다 (3)
== 이걸 토대로 구조체를 구성한다. 
*/ 

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, k, a, b, ret;
struct A{
	ll id, _time, cache;
};
vector<A> v; 
// pq.top이 pop되면서 쇼핑몰을 빠져나가는 고객들을 기준으로
// 어떤 vector안에 넣되 새로운 정렬 기준을 가지게 하면된다. (문제의 조건대로) 

struct cmp{
	bool operator()(A a, A b){
		if(a._time == b._time){
			return a.cache > b.cache;
		}else return a._time > b._time;
	}
};

bool cmp2(A a, A b){
	if(a._time == b._time){
		return a.cache > b.cache;
	}else return a._time < b._time;
}
int main(){
	cin >> n >> k;
	
	priority_queue<A, vector<A>, cmp> pq;
	
	for(int i = 1; i <= n; i++){
		cin >> a >> b;
		
		// i + 1이 지금까지 고객의 수. 이 경우는 그냥 계산대에 쑥 들어갈 수 있다. 
		if(i <= k){
			pq.push({a, b, i});
		}else{
			ll temp_id = pq.top().id, temp_time =  pq.top()._time, temp_cache = pq.top().cache;
			pq.pop();
			pq.push({a, temp_time + b, temp_cache});
			v.push_back({temp_id, temp_time, temp_cache});
		}
		// 이제 pq에 push를 할건데... pq.top은 가장 먼저 끝나고, 번호가 작은 계산대여야 한다.
		// 우선순위큐는 반대로 구현을 해줘야한다. 
		
		// 한편, pq.top은 빠져나가는 고객이므로 이 고객이 빠져나가는 A에 대해서 
		// 시간이 작은 순서대로 정렬, 만약 시간이 같다면 계산대 번호가 높은 순서대로. 
	}
	while(pq.size()){
		v.push_back(pq.top());
		pq.pop();
	} // 아직 pq안에 남아있는 것들 제거! 
	sort(v.begin(), v.end(), cmp2);
	
	for(ll i = 1; i <= v.size(); i++){
		ret += i * v[i - 1].id; 
	}
	cout << ret << "\n";
	return 0;
}