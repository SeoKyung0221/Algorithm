#include<bits/stdc++.h>
using namespace std;
int point[10] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1}, te, tcnt, n, x, y, ret;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> te;
	while(te--){
		tcnt++;
		ret = 0;
		
		cin >> n;
		for(int i = 0; i < n; i++){
			cin >> x >> y;
			double p = sqrt(pow(x, 2) + pow(y, 2)) / 20;
			int q = sqrt(pow(x, 2) + pow(y, 2)) / 20;
			if(p > 10) continue;
			if(p - q == 0){
				if(q == 0){
					ret += point[0];
					continue;
				}
				ret += point[q - 1];
			}else{
				ret += point[q];
			}
		}
		cout << "#" << tcnt << " " << ret << "\n";
	}
}