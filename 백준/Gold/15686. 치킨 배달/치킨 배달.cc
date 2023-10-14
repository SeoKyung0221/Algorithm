#include<bits/stdc++.h>
using namespace std;
int n, m, a[54][54], ret = 1e9;
vector<pair<int,int>> h, c;
vector<vector<int>> v;

void combi(int start, vector<int> &b){
	if(b.size() == m){
		v.push_back(b);
		return;
	}
	for(int i = start + 1; i < c.size(); i++){
		b.push_back(i);
		combi(i, b);
		b.pop_back();
	}
	return;
}
int main(){
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin >> a[i][j];
			if(a[i][j] == 1) h.push_back({i, j});
			else if(a[i][j] == 2) c.push_back({i, j});
		}
	}
	vector<int> b;
	combi(-1, b);
	for(vector<int> i : v){
		int sum = 0;
		for(auto j : h){
			int cur = 1e9;
			for(int k : i){
				cur = min(cur, abs(j.first - c[k].first) + abs(j.second - c[k].second));
			}
			sum += cur;
		}
		ret = min(ret, sum);
	}
	cout << ret << "\n";
}