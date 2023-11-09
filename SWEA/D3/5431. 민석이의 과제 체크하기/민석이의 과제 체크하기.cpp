#include<bits/stdc++.h>
using namespace std;
int te, tcnt, n, k, num, a[104];

int main(){
	cin >> te;
	while(te--){
		tcnt++;
		fill(a, a + 104, 0);
		
		cin >> n >> k;
		for(int i = 0; i < k; i++){
			cin >> num;
			a[num] = 1;
		}
		cout << "#" << tcnt << " ";
		for(int i = 1; i <= n; i++){
			if(a[i] == 0) cout << i << " ";
		}
		cout << "\n";
	}
}