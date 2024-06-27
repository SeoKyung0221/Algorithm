#include<bits/stdc++.h>
using namespace std;
int n, m, a, b, visited[104];
vector<int> adj[104];
map<int, int> ret;

bool cmp(pair<int, int> a, pair<int, int> b){
	if(a.second == b.second) return a.first < b.first;
	else return a.second < b.second;
}
int main(){
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	for(int i = 1; i <= n; i++){
		memset(visited, 0, sizeof(visited));
		visited[i] = 1;
		queue<int> q;
		q.push(i);
		while(q.size()){
			int here = q.front();
			q.pop();
			for(int to : adj[here]){
				if(visited[to]) continue;
				visited[to] = visited[here] + 1;
				q.push(to);
			}
		}
		
		for(int j = 1; j <= n; j++){
			if(i == j) continue;
			ret[i] += visited[j] - 1;
		}
	}
	vector<pair<int, int>> v;
	for(int i = 1; i <= n; i++){
		v.push_back({i, ret[i]});
	}
	sort(v.begin(), v.end(), cmp);
	
	cout << v[0].first << "\n";
}