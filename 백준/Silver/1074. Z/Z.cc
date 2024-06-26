#include<bits/stdc++.h>
using namespace std;
int n, r, c, ret;

void go(int a, int b, int size){
	if(a == r && b == c){
		cout << ret << "\n";
		return;
	}else if(r <  a + size && r >= a && c < b + size && c >= b){
		go(a, b, size / 2);
		go(a , b + size / 2, size / 2);
		go(a + size / 2, b, size / 2);
		go(a + size / 2, b + size / 2, size / 2);
	}else{
		ret += size * size;
	}
}
int main(){
	cin >> n >> r >> c;
	int t = pow(2, n);
	
	go(0, 0, t);
	return 0;
}