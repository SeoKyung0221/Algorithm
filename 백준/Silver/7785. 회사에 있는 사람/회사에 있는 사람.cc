#include<bits/stdc++.h>
using namespace std;
int n;
string name, ee;
map<string, int> mp;
vector<string> v;
int main(){
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> name >> ee;
		if(ee == "enter"){
			mp[name]++;
		}else{
			mp[name] = 0;
		}
	}
	for(auto it = mp.begin(); it != mp.end(); it++){
		if((*it).second != 0){
			v.push_back((*it).first);
		}
	}
	for(int i = v.size()-1; i >= 0; i--){
		cout << v[i] << "\n";
	}
}