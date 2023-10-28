#include<bits/stdc++.h>
using namespace std;
int te, tcnt, p, q;
vector<pair<int,int>> v;

void _fill(){
	for(int i = 1; i <= 300; i++){
		int y = i;
		int x = 1;
		v.push_back({y, x});
		while(true){
			int ny = y - 1;
			int nx = x + 1;
			if(ny < 1) break;
			v.push_back({ny, nx});
			y = ny;
			x = nx;
		}
	}
}
int main(){
	cin >> te;
	_fill();
	while(te--){
		tcnt++;
		cin >> p >> q;
		int a = v[p-1].first + v[q-1].first;
		int b = v[p-1].second + v[q-1].second;
		int ret = find(v.begin(), v.end(), make_pair(a, b)) - v.begin();
		cout << "#" << tcnt << " " << ret + 1 << "\n";
	}
}