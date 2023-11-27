#include<bits/stdc++.h>
using namespace std;
int n, k, visited[200004], cnt[200004];

int main(){
	cin >> n >> k;
	visited[n] = 1;
	cnt[n] = 1;
	queue<int> q;
	q.push(n);
	while(q.size()){
		int here = q.front();
		q.pop();
		for(int next : {here - 1, here + 1, here * 2}){
			if(next < 0 || next >= 200004) continue;
			if(!visited[next]){
				visited[next] = visited[here] + 1;
				cnt[next] += cnt[here];
				q.push(next);
			}else if(visited[next] == visited[here] + 1){
				cnt[next] += cnt[here];
			}
		}
	}
	cout << visited[k] - 1 << "\n" << cnt[k] << "\n";
}