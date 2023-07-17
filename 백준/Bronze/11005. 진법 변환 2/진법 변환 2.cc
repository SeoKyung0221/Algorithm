#include<bits/stdc++.h>
using namespace std;
int s, b;
string ret = "";

int main(){
	cin >> s >> b;
	
	while(s >= b){
		int a = s % b;
		if(a >= 0 && a <= 9){
			ret = char(a + '0') + ret;
		}else{
			ret = char(a - 10 + 'A') + ret;
		}
		s /= b;
	}
	if(s >= 0 && s <= 9){
		ret = char(s + '0') + ret;
	} else{
		ret = char(s - 10 + 'A') + ret;
	}
	
	cout << ret << "\n";
}