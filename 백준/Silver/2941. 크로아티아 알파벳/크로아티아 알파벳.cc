#include<bits/stdc++.h>
using namespace std;
string s, a[8] = {"c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z="};
int ret;
int main(){
	cin >> s;
	for(int i = 0; i < 8; i++){
		long long pos = 0;
		while((pos = s.find(a[i])) != string::npos){
			if(i == 2){
				ret++;
				s.erase(pos, 3);
				s.insert(pos, "---");
			}else {
				ret++;
				s.erase(pos, 2);
				s.insert(pos, "--");
			}
		}
	}
	for(char i : s){
		if(i != '-') ret++;
	}
	cout << ret << "\n";
}