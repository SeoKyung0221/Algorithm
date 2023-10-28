#include<bits/stdc++.h>
using namespace std;
int a, b, c, p, q, k[104], mx, ret;

int main(){
	cin >> a >> b >> c;
	for(int i = 0; i < 3; i++){
		cin >> p >> q;
		for(int i = p; i < q; i++) k[i]++;
		mx = max(mx, q);
	}
	for(int i = 0; i <= mx; i++){
		if(k[i] == 0) continue;
		else if(k[i] == 1) ret += a;
		else if(k[i] == 2) ret += 2 * b;
		else ret += 3 * c;
	}
	cout << ret << "\n";
}