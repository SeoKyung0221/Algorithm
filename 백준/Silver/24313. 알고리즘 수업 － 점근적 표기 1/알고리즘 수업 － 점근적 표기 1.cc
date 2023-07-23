#include<bits/stdc++.h>
using namespace std;
int a1, a0, c, n;

int main(){
	int ret = 0;
	cin >> a1 >> a0;
	cin >> c;
	cin >> n;
	
	if(c-a1 < 0){
		cout << 0 << "\n";
		return 0;
	}
	if((c-a1) * n >= a0) cout << 1 << "\n";
	else cout << 0 << "\n";
}