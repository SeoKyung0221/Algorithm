#include<bits/stdc++.h>
using namespace std;
int n, a[11], visited[11], num, b, ret = 1e9, comp[11];
vector<int> adj[11];

pair<int, int> dfs(int here, int value){
    visited[here] = 1; 
    pair<int, int> ret = {1, a[here]}; 
    for(int there : adj[here]){
        if(comp[there] != value) continue; 
        if(visited[there]) continue; 
        pair<int, int> _temp = dfs(there, value); 
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
		int hereZ = 0, hereO = 0;
		fill(comp, comp + 11, 0);
		fill(visited, visited + 11, 0);
		for(int j = 0; j < n; j++){
			if(i & (1 << j)){
				hereO = j + 1;
				comp[j+1] = 1;
			}else{
				hereZ = j + 1;
			}
			}
			pair<int, int> z = dfs(hereZ, 0);
			pair<int, int> o = dfs(hereO, 1);
			if(z.first + o.first == n){
				ret = min(ret, abs(z.second - o.second));
		}
	}
	if(ret == 1e9) cout << "-1\n";
	else cout << ret << "\n";
}