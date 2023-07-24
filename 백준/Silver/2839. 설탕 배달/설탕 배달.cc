#include<bits/stdc++.h>
using namespace std;
int n, ret = 1e9;
int main(){
	cin >> n;
	int a = 0;
	int b = 0;
	if(n % 3 == 0){
		a = n / 3;
	}else a = n / 3 + 1;
	if(n % 5 ==0){
		b = n / 5;
	}else b = n / 5 + 1;
	int flag = 0;
	for(int i = 0; i <= a; i++){
		for(int j = 0; j <= b; j++){
			if(i * 3 + j * 5 == n){
				flag = 1;
				ret = min(ret, i + j);
			}
		}
	}
	if(flag) cout << ret << "\n";
	else cout << -1 << "\n";
}