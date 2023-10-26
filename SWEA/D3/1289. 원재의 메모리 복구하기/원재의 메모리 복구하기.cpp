#include<bits/stdc++.h>
using namespace std;
int te, tcnt;
string s;

int main(){
	cin >> te;
	while(te--){
		tcnt++;
		int ret = 0;
		int k = 0;
		cin >> s;
		for(int i = 0; i < s.size(); i++){
			if(s[i] - '0' != k){
				k = s[i] - '0';
				ret++;
			}
		}
		cout << "#" << tcnt << " " << ret << "\n";
	}
}