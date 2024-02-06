#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define y1 aaaa
ll n, m, a[1028][1028], b[1028][1028], w, x, y, c, x1, y1, x2, y2;

ll sum(ll b[1028][1028], int i, int j){
	ll ret = 0;
	while(i > 0){
		int x = j;
		while(x > 0){
			ret += b[i][x];
			x -= (x & -x);
		}
		i -= (i & -i);
	}
	return ret;
}
void update(ll b[1028][1028], int i, int j, ll diff){
	while(i < 1028){
		int x = j;
		while(x < 1028){
			b[i][x] += diff;
			x += (x & -x);
		}
		i += (i & -i);
	}
	return;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			cin >> a[i][j];
			update(b, i, j, a[i][j]);
		}
	}
	for(int i = 0; i < m; i++){
		cin >> w;
		if(w == 0){
			cin >> x >> y >> c;
			ll diff = c - a[x][y];
			update(b, x, y, diff);
			a[x][y] = c;
		}else{
			cin >> x1 >> y1 >> x2 >> y2;
			cout << sum(b, x2, y2) - sum(b, x1 - 1, y2) - sum(b, x2, y1 - 1) + sum(b, x1 - 1, y1 - 1) << "\n";
		}
	}
}