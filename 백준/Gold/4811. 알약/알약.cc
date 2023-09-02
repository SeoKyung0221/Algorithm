#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, dist[64][64];

ll go(int w, int h){
	if(w == 0 && h == 0) return 1;
	if(w < 0 || h < 0) return 0;
	
	ll &ret = dist[w][h];
	if(ret != 0) return ret;
	
	ret = 0;
	ret = go(w - 1, h + 1) + go(w, h - 1);
	
	return ret;
}
int main(){
	while(true){
		fill(&dist[0][0], &dist[0][0] + 64 * 64, 0);
		cin >> n;
		if(n == 0) break;
		cout << go(n, 0) << "\n";
	}
}