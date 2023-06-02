#include<bits/stdc++.h>
using namespace std;
string s;
int ret, cnt, cnt2;
map<int, int> mp;
int main(){
	cin >> s;
	for(auto i : s){
		if(i - 'a' >= 0 && i - 'a' <= 25){
			mp[i-'a']++;
		}
		else{
			mp[i- 'A']++;
		}
	}
	for(auto it = mp.begin(); it!= mp.end(); it++){
		if(cnt < (*it).second){
			ret = (*it).first;
			cnt = (*it).second;
		}
	}
	for(auto it = mp.begin(); it!= mp.end(); it++){
		if(cnt == (*it).second){
			cnt2++;
		}
	}
	if(cnt2 == 1){
		cout << char(ret+'A') << "\n";
	} else
		cout << "?\n";
	return 0;
}