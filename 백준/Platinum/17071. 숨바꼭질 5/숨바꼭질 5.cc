#include<bits/stdc++.h>
using namespace std;
const int MAX_N = 500000;
int n, k, visited[2][MAX_N + 4], ok, turn = 1;

int main(){
	cin >> n >> k;
	if(n == k){
		cout << 0 << "\n";
		return 0;
	}
	queue<int> q;
	visited[0][n] = 1;
	q.push(n);
	while(q.size()){
		k += turn;
		
		if(k > MAX_N) break;
		if(visited[turn % 2][k]){
			ok = 1;
			break;
		}
		int qSize = q.size();
		for(int i = 0; i < qSize; i++){
			int x = q.front(); q.pop();
			for(int nx : {x-1, x+1, x*2}){
				if(nx < 0 || nx > MAX_N || visited[turn % 2][nx]) continue;
				visited[turn % 2][nx] = 1;
				if(nx == k){
					ok = 1;
					break;
				}
				q.push(nx);
			}
			if(ok) break;
		}
		if(ok) break;
		turn++;
	}
	if(ok) cout << turn << "\n";
	else cout << -1 << "\n";
}