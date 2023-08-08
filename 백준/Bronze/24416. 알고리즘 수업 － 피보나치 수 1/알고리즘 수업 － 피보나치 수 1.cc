#include<bits/stdc++.h>
using namespace std;
int n, ret1, ret2, f[44];

int fib(int n){
	if(n == 1 || n == 2){
		ret1++;
		return 1;
	}
	else return fib(n-1) + fib(n-2);
}

int fibonacci(int n){
	f[1] = 1, f[2] = 1;
	for(int i = 3; i <= n; i++){
		ret2++;
		f[i] = f[i - 1] + f[i - 2];
	}
	return f[n];
}

int main(){
	cin >> n;
	fib(n); fibonacci(n);
	cout << ret1 << " " << ret2 << "\n";
}