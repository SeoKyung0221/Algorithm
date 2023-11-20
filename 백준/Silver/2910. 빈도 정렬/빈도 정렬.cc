#include<bits/stdc++.h>
using namespace std;
int n, c, num;
vector<int> v;
map<int, int> mp, mp_first;

bool cmp(int a, int b){
	if(mp[a] == mp[b]){
		return mp_first[a] < mp_first[b];
	}else{
		return mp[a] > mp[b];
	}
}
int main(){
	cin >> n >> c;
	for(int i = 0; i < n; i++){
		cin >> num;
		v.push_back(num);
		mp[num]++;
		if(mp_first[num] == 0) mp_first[num] = i+1;
	}
	sort(v.begin(), v.end(), cmp);
	
	for(int i : v){
		cout << i << " ";
	}
}