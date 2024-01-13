#include<bits/stdc++.h>
using namespace std;
int n, s, e, ret = 1;
vector<pair<int,int>> v;

int main(){
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> s >> e;
		v.push_back({s,e});
	}
	sort(v.begin(), v.end());
	int a = v[0].first;
	int b = v[0].second;
	for(int i = 1; i < n; i++){
		if(b > v[i].first){
			if(b > v[i].second){
				b = v[i].second;
			}
		} else{
			b = v[i].second;
			ret++;
		}
	}
	cout << ret << "\n";
}