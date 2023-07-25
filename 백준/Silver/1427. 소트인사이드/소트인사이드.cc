#include<bits/stdc++.h>
using namespace std;
string s;
vector<int> v;
int main(){
	cin >> s;
	for(int i = 0; i < s.size(); i++){
		v.push_back(s[i] - '0');
	}
	sort(v.begin(), v.end(), greater<int>());
	for(int i : v){
		cout << i;
	}
}