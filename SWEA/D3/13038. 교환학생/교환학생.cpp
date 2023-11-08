#include<bits/stdc++.h>
using namespace std;
int n, te, tcnt, a[10], ret;

int go(int start){
	int ans = 0;
	int cnt = 0;
	int flag = 0;
	
	int i = start;
	while(true){
		for(; i < 7; i++){
			if(a[i] == 1) cnt++;
			ans++;
			if(cnt == n){
				flag = 1;
				break;
			}
		}
		if(flag) break;
		i = 0;
	}
	return ans;
}
int main(){
	cin >> te;
	while(te--){
		tcnt++;
		ret = 1e9;
		
		cin >> n;
		for(int i = 0; i < 7; i++){
			cin >> a[i];
		}
		for(int i = 0; i < 7; i++){
			ret = min(ret, go(i));
		}
		cout << "#" << tcnt << " " << ret << "\n";
	}
    return 0;
}