#include<bits/stdc++.h>
using namespace std;
int n, p, l, m, x;
string s;

set<pair<int, int>> st;
map<int, int> mp;

int main(){
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> p >> l;
		
		mp[p] = l;
		st.insert({l, p});
	}

	cin >> m;
	for(int i = 0; i < m; i++){
		cin >> s;
		if(s == "recommend"){
			cin >> x;
			if(x == 1){
				auto it = st.rbegin();
				cout << it -> second << "\n";
			}else if(x == -1){
				auto it = st.begin();
				cout << (*it).second << "\n";
			}
		}else if(s == "add"){
			cin >> p >> l;
			st.insert({l, p});
			mp[p] = l;
		}else if(s == "solved"){
			cin >> p;
			
			st.erase({mp[p], p});
			mp[p] = 0;
		}
	}
}