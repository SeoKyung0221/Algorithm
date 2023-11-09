#include<bits/stdc++.h>
using namespace std;
int te, tcnt, n, q, l, r, a[1004];

int main(){
	cin >> te;
	while(te--){
		fill(a, a + 1004, 0);
		tcnt++;
		cin >> n >> q;
		for(int i = 1; i <= q; i++){
			cin >> l >> r;
			for(int j = l; j <= r; j++){
				a[j] = i;
			}
		}
		cout << "#" << tcnt << " ";
		for(int i = 1; i <= n; i++){
			cout << a[i] << " ";
		}
		cout << "\n";
	}
}