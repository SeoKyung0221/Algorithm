#include<bits/stdc++.h>
using namespace std;
#define kkkk time
int n, k, ok, turn = 1, visited[2][500004];

int main(){
	cin >> n >> k;
    if(n == k){
        cout << 0 << "\n";
        return 0;
    }
	
	visited[0][n] = 1;
	queue<int> q;
	q.push(n);
	
	while(q.size()){
		k += turn;
		if(k > 500000) break;
		if(visited[turn % 2][k]){
			ok = 1;
			break;
		}
		int qSize = q.size();
		for(int i = 0; i < qSize; i++){
			int here = q.front(); q.pop();
			for(int next : {here - 1, here + 1, here * 2}){
				if(next < 0 || next > 500000) continue;
				if(visited[turn % 2][next]) continue;
				visited[turn % 2][next] = 1;
				if(next == k){
					ok = 1;
					break;
				}
				q.push(next);
			}
			if(ok) break;
		}
		if(ok) break;
		turn++;
	}
	if(ok) cout << turn << "\n";
	else cout << -1 << "\n";
}