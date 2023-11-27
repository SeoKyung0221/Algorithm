#include<bits/stdc++.h>
using namespace std;
#define prev aaaa
int n, k, visited[200004], prev[200004], ret;
vector<int> v;

int main(){
	cin >> n >> k;
	
	visited[n] = 1;
	queue<int> q;
	q.push(n);
	
	while(q.size()){
		int here = q.front();
		q.pop();
		for(int next : {here - 1, here + 1, here * 2}){
			if(next < 0 || next >= 200004) continue;
			if(visited[next]) continue;
			visited[next] = visited[here] + 1;
			prev[next] = here;
			q.push(next);
		}
	}
	for(int i = k; i != n; i = prev[i]){
		v.push_back(i);
	}
	v.push_back(n);
	cout << visited[k] - 1 << "\n";
	reverse(v.begin(), v.end());
	for(int i : v){
		cout << i << " ";
	}
}