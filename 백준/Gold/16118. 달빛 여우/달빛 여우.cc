#include<bits/stdc++.h>
using namespace std;
typedef tuple<int, int, bool> TI;
int n, m, a, b, d, dist[4004], dist_wolf[4004][2], ret;
const int INF = 1e9;
vector<pair<int,int>> adj[4004];

void dikstra(){
	fill(dist, dist + 4004, INF);
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	dist[1] = 0;
	pq.push({0, 1});
	while(pq.size()){
		int here = pq.top().second;
		int here_dist = pq.top().first;
		pq.pop();
		if(dist[here] != here_dist) continue;
		for(auto i : adj[here]){
			int next = i.second;
			int next_dist = i.first;
			if(dist[next] > dist[here] + next_dist){
				dist[next] = dist[here] + next_dist;
				pq.push({dist[next], next});
			}
		}
	}
}
void dikstra2(){ 
    fill(&dist_wolf[0][0], &dist_wolf[0][0] + 4001 * 2, INF);
    priority_queue<TI, vector<TI>, greater<TI>> PQ; 
    dist_wolf[1][0] = 0;   
    PQ.push(make_tuple(0, 1, 0));
    while(PQ.size()){
        int d, here, cnt; 
        tie(d, here, cnt) = PQ.top();
        PQ.pop();    
		if(dist_wolf[here][cnt] != d) continue;
        for(auto there : adj[here]){
            int next = there.second; 
            int d = !cnt ? there.first / 2 : there.first * 2;    
            if(dist_wolf[next][!cnt] > dist_wolf[here][cnt] + d){ 
                dist_wolf[next][!cnt] = dist_wolf[here][cnt] + d; 
                PQ.push(make_tuple(dist_wolf[next][!cnt], next, !cnt));
            } 
        }
    }       
} 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		cin >> a >> b >> d;
		adj[a].push_back({2 * d, b});
		adj[b].push_back({2 * d, a});
	}
	dikstra();
	dikstra2();
	
	for(int i = 2; i <= n; i++){
		int k = min(dist_wolf[i][0], dist_wolf[i][1]);
		if(k > dist[i]) ret++;
	}
	cout << ret << "\n";
}