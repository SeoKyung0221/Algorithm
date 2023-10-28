#include<bits/stdc++.h>
using namespace std;
int t, n;
string s1, s2;
int main(){
	cin >> t;
	while(t--){
		map<string, int> mp1;
		cin >> n;
		for(int i = 0; i < n; i++){
			cin >> s1 >> s2;
			mp1[s2]++;
		}
		int ret = 1; 
		for(auto i : mp1){
			ret *= (i.second+1);
		}
		ret--;
		cout << ret << "\n";
	}
	return 0;
}