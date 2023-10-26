#include<bits/stdc++.h>
using namespace std;
int n, a[100], ret;

void go(int cnt){
	int posMx = max_element(a, a + 100) - a;
	int posNx = min_element(a, a + 100) - a;
	int mx = a[posMx];
	int nx = a[posNx];
	if(cnt == 0 || (mx - nx <= 1)){
		ret = mx - nx;
		return;
	}
	a[posMx] -= 1;
	a[posNx] += 1;
	go(cnt - 1);
}
int main(){
	for(int te = 1; te <= 10; te++){
		fill(a, a + 104, 0);
		
		cin >> n;
		for(int i = 0; i < 100; i++){
			cin >> a[i];
		}
		go(n);
		cout << "#" << te << " " << ret << "\n";
	}
}