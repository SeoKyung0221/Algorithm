#include<bits/stdc++.h>
using namespace std;
int n, m, ret;
string s;
map<string, int> mp;
vector<string> v;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		cin >> s;
		mp[s]++;
	}
	for(int i = 0; i < m; i++){
		cin >> s;
		mp[s]++;
	}
	for(auto it = mp.begin(); it != mp.end(); it++){
		if((*it).second == 2){
			ret++;
			v.push_back((*it).first);
		}
	}
	cout << ret << "\n";
	sort(v.begin(), v.end());
	for(string i : v){
		cout << i << "\n";
	}
}