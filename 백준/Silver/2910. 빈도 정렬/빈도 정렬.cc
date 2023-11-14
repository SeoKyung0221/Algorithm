#include<bits/stdc++.h>
using namespace std;
int n, c, num;
map<int, int> mp, mp_first;
vector<pair<int, int>> v;

bool cmp(pair<int, int> a, pair<int, int> b){
	if(a.second == b.second){
		return mp_first[a.first] < mp_first[b.first];
	}else return a.second > b.second;
}
int main(){
	cin >> n >> c;
	for(int i = 0; i < n; i++){
		cin >> num;
		mp[num]++;
		if(mp_first[num] == 0) mp_first[num] = i+1;
	}
	for(auto it : mp){
		v.push_back({it.first, it.second});
	}
	sort(v.begin(), v.end(), cmp);
	
	for(auto i : v){
		for(int j = 0; j < i.second; j++){
			cout << i.first << " ";
		}
	}
}