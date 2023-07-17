#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, ret;

int main(){
	cin >> n;
	ret = ll(pow(2, 2*n)) + ll(pow(2, n)) * 2 + 1;
	
	cout << ret << "\n";
}