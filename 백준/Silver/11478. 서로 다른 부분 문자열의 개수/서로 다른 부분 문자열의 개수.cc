#include<bits/stdc++.h>
using namespace std;
int ret;
string s;
set<string> st;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> s;
	for(int i = 0; i < s.size(); i++){
		string str = "";
		for(int j = i; j < s.size(); j++){
			str += s[j];
			st.insert(str);
		}
	}
	cout << st.size() << "\n";
}