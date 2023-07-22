#include<bits/stdc++.h>
using namespace std;
int a, b, c, mx;
int main(){
	cin >> a >> b >> c;
	mx = max(mx, a);
	mx = max(mx, b);
	mx = max(mx, c);
	
	if(mx == a){
		if(a < b + c) cout << a+b+c;
		else{
			cout << 2*(b + c) - 1;
		}
	}else if(mx == b){
		if(b < a + c) cout << a+b+c;
		else{
			cout << 2*(a + c) - 1;
		}
	}else if(mx == c){
		if(c < b + a) cout << a+b+c;
		else{
			cout << 2*(b + a) - 1;
		}
	}
}