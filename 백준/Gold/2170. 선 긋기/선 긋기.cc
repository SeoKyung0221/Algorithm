#include<bits/stdc++.h>
using namespace std;
int n, x, y, ret;
vector<pair<int,int>> v;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for(int i = 0 ; i < n; i++){
		cin >> x >> y;
		v.push_back({x,y});
	}
	sort(v.begin(), v.end());
	
	int a = v[0].first;
	int b = v[0].second;
	
	for(int i = 1; i < n; i++){
		if(b > v[i].second) continue;
		if(b < v[i].first){
			ret += b - a;
			a = v[i].first;
			b = v[i].second;
		} else {
			b = v[i].second;
		}
	}
	ret += b - a;
	cout << ret << "\n";
}