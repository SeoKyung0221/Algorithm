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
		v.push_back(s);
	}
	sort(v.begin(), v.end(), cmp);
	v.erase(unique(v.begin(), v.end()), v.end());
	for(string i : v){
		cout << i << "\n";
	}
}