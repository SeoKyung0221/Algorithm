#include<bits/stdc++.h>
using namespace std;
const int dy[] = {0, 1, -1};
int n, a[104][104], ret;

void solve(){
	for(int j = 0; j < 100; j++){
        int flag = 0;
		for(int i = 0; i < 100; i++){
			if(a[i][j] == 1) flag = 1;
			else if(flag && a[i][j] == 2){
				ret++;
				flag = 0;
			}
		}
	}
}
int main(){
	// 빨강 1, 파랑 2 
	for(int te = 1; te <= 10; te++){
		ret = 0;
		cin >> n;
		for(int i = 0; i < 100; i++){
			for(int j = 0; j < 100; j++){
				cin >> a[i][j];
			}
		}
		solve();
		cout << "#" << te << " " << ret << "\n";
	}
}