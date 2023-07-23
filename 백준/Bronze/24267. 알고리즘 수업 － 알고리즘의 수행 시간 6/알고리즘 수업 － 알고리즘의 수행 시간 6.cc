#include<bits/stdc++.h>
using namespace std;
long long n, ret;

int main(){
	cin >> n;
	
	for(int i = 1; i <= n-2; i++){
		ret += (n-i) * (n-i-1) / 2;
	}
	cout << ret << "\n" << 3 << "\n";
}