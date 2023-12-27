#include<bits/stdc++.h>
using namespace std;
int n, k, visited[1000004];

int main(){
	cin >> n >> k;
	if(n == k){
		cout << 0 << "\n";
		return 0;
	}
	queue<int> q;
	q.push(n);
	visited[n] = 1;
	while(q.size()){
		int here = q.front();
		q.pop();
		for(int next : {here - 1, here + 1, here * 2}){
			if(next < 0 || next > 100000) continue;
			if(visited[next]) continue;
			visited[next] = visited[here] + 1;
			q.push(next);
		}
	}
	cout << visited[k] - 1 << "\n";
}