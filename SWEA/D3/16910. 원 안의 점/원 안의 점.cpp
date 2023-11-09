#include<bits/stdc++.h>
using namespace std;
int te, tcnt, n, ret;

int main(){
	cin >> te;
	while(te--){
		tcnt++;
		ret = 0;
		
		cin >> n;
		for(int x = -n; x <= n; x++){
			for(int y = -n; y <= n; y++){
				if(x * x + y * y <= n * n) ret++;
			}
		}
		cout << "#" << tcnt << " " << ret << "\n";
	}
}