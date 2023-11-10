#include<bits/stdc++.h>
using namespace std;
int te, tcnt, n;
string a, b, s[10] = {"ZRO", "ONE", "TWO", "THR", "FOR", "FIV", "SIX", "SVN", "EGT", "NIN"};

int main(){
	cin >> te;
	while(te--){
		tcnt++;
		vector<int> v;
		cin >> a >> n;
		for(int i = 0; i < n; i++){
			cin >> b;
			for(int j = 0; j < 10; j++){
				if(b == s[j]){
					v.push_back(j);
				}
			}
		}
		sort(v.begin(), v.end());
		cout << "#" << tcnt << "\n";
		for(int i : v){
			cout << s[i] << " ";
		}
		cout << "\n";
	}
} 