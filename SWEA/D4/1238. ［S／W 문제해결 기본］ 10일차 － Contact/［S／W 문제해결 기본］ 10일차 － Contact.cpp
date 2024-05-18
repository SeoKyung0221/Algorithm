#include<bits/stdc++.h>
using namespace std;
int n, s, a, b, visited[104];

int main(){
	for(int te = 1; te <= 10; te++){
        int mx = 0, mx2 = 0;
		vector<int> adj[104];
        memset(visited, 0, sizeof(visited));
    	cin >> n >> s;
        
        for(int i = 0; i < n / 2; i++){
        	cin >> a >> b;
            adj[a].push_back(b);
        }
        
        visited[s] = 1;
        queue<int> q;
        q.push(s);
        while(q.size()){
        	int here = q.front();
            q.pop();
            for(int to : adj[here]){
            	if(visited[to]) continue;
                visited[to] = visited[here] + 1;
                q.push(to);
            }
        }
        for(int i = 1; i <= 100; i++){
        	if(mx2 <= visited[i]){
            	mx2 = visited[i];
                mx = i;
            }
        }
        cout << "#" << te << " " << mx << "\n";
	}
}