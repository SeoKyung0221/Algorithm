#include<bits/stdc++.h>
using namespace std;
int n, x;
vector<int> v;
vector<int> v2;
map<int, int> mp;

int main(){
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> x;
		v.push_back(x);
		v2.push_back(x);
	}
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	
	for(int i = 0; i < v.size(); i++){
		mp[v[i]] = i;
	}
	for(int i : v2){
		cout << (*mp.find(i)).second << " ";
	}
} 