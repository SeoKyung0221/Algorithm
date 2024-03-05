#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, a[1000004], b, c, ret;

int main(){
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	cin >> b >> c;
	for(int i = 0; i < n; i++){
		if(a[i] <= b) ret += 1;
		else{
			if((a[i] - b) % c == 0) ret += (a[i] - b) / c;
			else ret += (a[i] - b) / c + 1;
			ret += 1;
		}
	}
	cout << ret << "\n";
}
