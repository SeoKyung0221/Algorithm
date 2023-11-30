#include<bits/stdc++.h>
using namespace std;
int n, k, visited[2][500004], turn = 1;

int main(){
	cin >> n >> k;
	if(n == k){
		cout << 0 << "\n";
		return 0;
	}
	
	visited[0][n] = 1;
	queue<int> q;
	q.push(n);
	int flag = 0;
	while(q.size()){
		k += turn;
		if(k > 500000){
			break;
		}
		if(visited[turn % 2][k]){
			flag = 1;
			break;
		}
		int qSize = q.size();
		for(int i = 0; i < qSize; i++){
			int here = q.front();
			q.pop();
			for(int next : {here - 1, here + 1, here * 2}){
				if(next < 0 || next > 500000) continue;
				if(visited[turn % 2][next]) continue;
				if(k == next){
					flag = 1;
					break;
				}
				visited[turn % 2][next] = 1;
				q.push(next);
			}
			if(flag) break;
		}
		if(flag) break;
		turn++;
	}
	if(flag) cout << turn << "\n";
	else cout << -1 << '\n';
}