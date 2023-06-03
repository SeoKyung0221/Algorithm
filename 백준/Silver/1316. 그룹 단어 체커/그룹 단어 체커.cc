#include<bits/stdc++.h>
using namespace std;
string s;
int n, ret, a[26];

int main(){
	cin >> n;
	for(int i = 0; i < n; i++){
		fill(&a[0], &a[0] + 26, 0);
		cin >> s;
		char k = s[0];
		a[k-'a'] = 1;
		int flag = 1;
		for(int j = 1; j < s.length(); j++){
			if(k != s[j] && a[s[j] - 'a'] != 0){
				flag = 0;
				break;
			}
			else if(k != s[j] & a[s[j] - 'a'] == 0){
				k = s[j];
				a[s[j] - 'a'] = 1;
			}
		}
		if(flag) ret++;
	}
	cout << ret << "\n";
}