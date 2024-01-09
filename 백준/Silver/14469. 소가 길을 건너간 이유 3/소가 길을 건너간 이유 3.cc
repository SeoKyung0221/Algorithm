#include<bits/stdc++.h>
using namespace std;
int n, a, b, ret;
vector<pair<int, int>> v;

int main(){
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> a >> b;
		v.push_back({a, b});
	}
	sort(v.begin(), v.end());
	ret = v[0].first + v[0].second;
	for(int i = 1; i < n; i++){
		if(ret < v[i].first){
			ret = v[i].first + v[i].second;
		}else{
			ret += v[i].second;
		}
	}
	cout << ret << "\n";
}