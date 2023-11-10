#include<bits/stdc++.h>
using namespace std;
int te, tcnt, n, ret;

int main(){
	cin >> te;
	while(te--){
		tcnt++;
		ret = 1;
		
		cin >> n;
		if(n == 1){
			cout << "#" << tcnt << " "<< 1 << "\n";
			continue;
		}
		for(int i = n/2 + 1; i >= 1; i--){
			int cnt = 0;
			for(int j = i; j >= 1; j--){
				cnt += j;
				if(cnt > n) break;
				else if(cnt == n){
					ret++;
					break;
				}else continue;
			}
		}
		cout << "#" << tcnt << " " << ret << "\n";
	}
}