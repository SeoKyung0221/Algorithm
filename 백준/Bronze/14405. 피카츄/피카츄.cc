#include<bits/stdc++.h>
using namespace std;
string s;

int main(){
	cin >> s;
	
	int flag = 0;
	while(true){
		if(s.size() == 0) break;
		if(s.substr(0, 2) == "pi"){
			s.erase(0, 2);
			continue;
		}else if(s.substr(0, 2) == "ka"){
			s.erase(0, 2);
			continue;
		}else if(s.substr(0, 3) == "chu"){
			s.erase(0, 3);
			continue;
		}else{
			flag = 1;
			break;
		}
	}
	if(flag) cout << "NO\n";
	else cout << "YES\n";
}