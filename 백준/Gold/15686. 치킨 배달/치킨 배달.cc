#include<bits/stdc++.h>
using namespace std;
int n, m, a[54][54], ret = 1e9;
vector<pair<int, int>> c, h;
vector<vector<int>> b;

void combi(int start, vector<int> v){
	if(v.size() == m){
		b.push_back(v);
		return;
	}
	for(int i = start + 1; i < c.size(); i++){
		v.push_back(i);
		combi(i, v);
		v.pop_back();
	}
	return;
}
int main(){
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin >> a[i][j];
			if(a[i][j] == 1) h.push_back({i,j});
			if(a[i][j] == 2) c.push_back({i,j});
		}
	}
	vector<int> v;
	combi(-1, v);
	for(vector<int> i : b){
		int sum = 0;
		for(auto home : h){
			int cur = 1e9;
			for(int ch: i){
				cur = min(cur, abs(home.first - c[ch].first) + abs(home.second - c[ch].second));
			}
			sum += cur;
		}
		ret = min(ret, sum);
	}
	cout << ret << "\n";
}