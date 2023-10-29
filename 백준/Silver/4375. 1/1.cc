#include<bits/stdc++.h>
using namespace std;
int n;

int main(){
	while(cin >> n){
		int cnt = 1, ret = 1;
		while(true){
			if(cnt % n == 0){
				cout << ret << "\n";
				break;
			}else{
				cnt = (cnt * 10) + 1;
				ret++;
				cnt %= n;
			}
		}
	}
}