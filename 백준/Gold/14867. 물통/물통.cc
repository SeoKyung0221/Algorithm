#include<bits/stdc++.h>
using namespace std;
int a, b, c, d;
map<pair<int, int>, int> mp;
queue<pair<int, int>> q;

void enqueue(int y, int x, int d){
	if(mp[{y, x}]) return;
	mp[{y, x}] = d + 1;
	q.push({y, x});
	return;
}
int main(){
	cin >> a >> b >> c >> d;
	mp[{0, 0}] = 1;
	q.push({0, 0});
	
	while(q.size()){
		int x, y;
		tie(x, y) = q.front();
		q.pop();
		
		enqueue(a, y, mp[{x, y}]);
		enqueue(x, b, mp[{x, y}]);
		enqueue(0, y, mp[{x, y}]);
		enqueue(x, 0, mp[{x, y}]);
		enqueue(min(x + y, a), max(y + x - a, 0), mp[{x, y}]);
		enqueue(max(x + y - b, 0), min(y + x, b), mp[{x, y}]);
	}
	if(mp[{c, d}] == 0) cout << -1 << "\n";
	else cout << mp[{c, d}] - 1<< "\n";
}