#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll te, tcnt, n, m, a[104], b[2004], c[104], x;
map<int, int> mp1;
int main(){
	cin >> te;
	while(te--){
		tcnt++;
		ll ret = 0;
		queue<ll> q;
		
		cin >> n >> m;
		for(int i = 0; i < n; i++){
			cin >> a[i];
		}
		for(int i = 1; i <= m; i++){
			cin >> b[i];
		}
		for(int i = 0; i < 2 * m; i++){
			cin >> x;
			if(x > 0){
				x;
				int flag = 1;
				for(int j = 0; j < n; j++){
					if(c[j] == 0){
						flag = 0;
						c[j] = x;
						mp1[x] = j;
						ret += a[j] * b[x];
						break;
					}
				}
				if(flag) q.push(x);
			}else{
				int k = abs(x);
				int temp = mp1[k];
				c[temp] = 0;
				if(q.size()){
					c[temp] = q.front();
					mp1[q.front()] = temp;
					ret += a[temp] * b[q.front()];
					q.pop();
				}
			}
			
		}
		cout << "#" << tcnt << " " << ret << "\n";
	}
}