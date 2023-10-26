#include<bits/stdc++.h>
using namespace std;
int n, a[11], visited[11], comp[11], num, b, ret = 1e9;
vector<int> adj[11];

pair<int, int> dfs(int here, int flag){
	visited[here] = 1;
	pair<int, int> ret = {1, a[here]};
	for(int i : adj[here]){
		if(visited[i]) continue;
		if(comp[i] != flag) continue;
		pair<int,int> _temp = dfs(i, flag);
		ret.first += _temp.first;
		ret.second += _temp.second;
	}
	return ret;
}
int main(){
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	for(int i = 1; i <= n; i++){
		cin >> num;
		for(int j = 0; j < num; j++){
			cin >> b;
			adj[i].push_back(b);
		}
	}
	for(int i = 1; i < (1 << n) - 1; i++){
		fill(visited, visited + 11, 0);
		fill(comp, comp + 11, 0);
		int hereZ = 0, hereO = 0;
		for(int j = 0; j < n; j++){
			if(i & (1 << j)){
				comp[j+1] = 1;
				hereO = j+1;
			}else{
				hereZ = j+1;
			}
		}
		pair<int, int> z = dfs(hereZ, 0);
		pair<int, int> o = dfs(hereO, 1);
		if(z.first + o.first == n){
			ret = min(ret, abs(z.second - o.second));
		}
	}
	if(ret == 1e9) cout << -1 << "\n";
	else cout << ret << "\n";
}