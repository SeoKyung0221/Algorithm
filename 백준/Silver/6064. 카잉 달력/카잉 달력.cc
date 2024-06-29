#include<bits/stdc++.h>
using namespace std;
int te, m, n, x, y, ret;

int gcd(int a, int b){
	if(a == 0) return b;
	else return gcd(b % a, a);
}

int lcm(int a, int b){
	return a * b / gcd(a, b);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> te;
	
	while(te--){
		cin >> m >> n >> x >> y;
		
		int ret = -1;
		
		int mNum = lcm(m, n);
		
		for(int i = x; i <= mNum; i += m){
			int ny = i % n;
			if(ny == 0) ny = n;
			
			if(ny == y){
				ret = i;
				break;
			}
		}
		cout << ret << "\n";
	}	
}