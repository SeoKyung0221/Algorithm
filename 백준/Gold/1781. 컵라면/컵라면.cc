#include<bits/stdc++.h>
using namespace std;
int n, d, c, ret;
priority_queue<int, vector<int>, greater<int>> pq;
vector<pair<int,int>> v;

int main(){
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> d >> c;
		v.push_back({d, c});
	}
	sort(v.begin(), v.end());
	for(int i = 0; i < n; i++){
		pq.push(v[i].second);
		if(pq.size() > v[i].first){
			pq.pop();
		}
	}
	while(!pq.empty()){
		ret += pq.top();
		pq.pop();
	}
	cout << ret << "\n";
}