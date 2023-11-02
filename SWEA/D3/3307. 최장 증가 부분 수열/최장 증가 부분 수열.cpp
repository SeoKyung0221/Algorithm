#include<bits/stdc++.h>
using namespace std;
int te, tcnt, n, num, lis[1004], len;

int main(){
	cin >> te;
	while(te--){
		tcnt++;
		fill(lis, lis + 1004, 0);
		len = 0;
		
		cin >> n;
		for(int i = 0; i < n; i++){
			cin >> num;
			auto lowerPos = lower_bound(lis, lis + len, num);
			if(*lowerPos == 0) len++;
			*lowerPos = num;
		}
		cout << "#" << tcnt << " " << len << "\n";
	}
}