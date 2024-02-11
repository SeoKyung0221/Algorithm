#include<bits/stdc++.h>
using namespace std;
string a, b, ret;

int main(){
	cin >> a >> b;
	
	int sum = 0;
	while(a.size() || b.size() || sum){
		if(a.size()){
			sum += a.back() - '0';
			a.pop_back();
		}
		if(b.size()){
			sum += b.back() - '0';
			b.pop_back();
		}
		ret += sum % 10 + '0';
		sum /= 10;
	}
	reverse(ret.begin(), ret.end());
	cout << ret << "\n";
}