#include<bits/stdc++.h>
using namespace std;
int n;
string s;
vector<string> v;

bool cmp(string a, string b){
	if(a.size() == b.size()) return a < b;
	else return a.size() < b.size();
}
int main(){
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> s;
		string cnt = "";
		int flag = 0;
		for(int j = 0; j < s.size(); j++){
			if(s[j] >= '0' && s[j] <= '9'){
				if(cnt == "0") cnt = "";
				cnt += s[j];
				flag = 1;
			}else if(flag == 1){
				v.push_back(cnt);
				flag = 0;
				cnt = "";
			}
		}
		if(cnt == "") continue;
		v.push_back(cnt);
	}
	sort(v.begin(), v.end(), cmp);
	for(string a : v){
		cout << a << "\n";
	}
}