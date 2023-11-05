#include<bits/stdc++.h>
using namespace std;
int te, tcnt, n, d, ret;

int main(){
	cin >> te;
	while(te--){
		tcnt++;
		ret = 1;
		
		cin >> n >> d;
		int here = 1 + d;
		while(here < n){
			if(here + d < n){
				ret++;
				here += 2 * d + 1;
			}else break;
		}
		cout << "#" << tcnt << " " << ret << "\n";
	}
}