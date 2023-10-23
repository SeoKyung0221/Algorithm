#include<bits/stdc++.h>
using namespace std;
int n, m, x, a, b, visited[100004];

int bfs(int x, vector<int> v[]){
	int ret = 0;
	queue<int> q;
	visited[x] = 1;
	q.push(x);
	while(q.size()){
		int here = q.front();
		q.pop();
		for(int i : v[here]){
			if(!visited[i]){
				visited[i] = 1;
				q.push(i);
				ret++;
			}
		}
	}
	return ret;
}
vector<int> h[100004], l[100004];
int main(){
	cin >> n >> m >> x;
	for(int i = 0; i < m; i++){
		cin >> a >> b;
		h[b].push_back(a);
		l[a].push_back(b);
	}
	int up = bfs(x, h);
	fill(visited, visited + 100004, 0);
	int down = bfs(x, l);
	
	cout << up + 1 << " " << n - down << "\n";
}