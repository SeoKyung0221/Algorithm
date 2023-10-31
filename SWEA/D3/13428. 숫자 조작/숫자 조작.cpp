#include<bits/stdc++.h>
using namespace std;
int te, tcnt, n;
string s, mn, mx;

string check_min(string a, string b){
	if(a.size() < b.size()) return a;
	else if(a.size() == b.size()){
		if(a > b) return b;
		else return a;
	}else return b;
}
string check_max(string a, string b){
	if(a.size() > b.size()) return a;
	else if(a.size() == b.size()){
		if(a > b) return a;
		else return b;
	}else return b;
}
int main(){
	cin >> te;
	while(te--){
		tcnt++;
		cin >> s;
		int n = s.size();
		
		mn = s;
		mx = s;
		
		for(int i = 0; i < n - 1; i++){
			for(int j = i + 1; j < n; j++){
				swap(s[i], s[j]);
				if(s[0] == '0'){
					swap(s[i], s[j]);
					continue;
				}
				mn = check_min(mn, s);
				mx = check_max(mx, s);
				swap(s[i], s[j]);
			}
		}
		cout << "#" << tcnt << " " << mn << " " << mx << "\n";
	}
}