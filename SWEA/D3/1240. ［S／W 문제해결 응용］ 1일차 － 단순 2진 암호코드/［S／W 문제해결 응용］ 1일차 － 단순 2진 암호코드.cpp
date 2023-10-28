#include<bits/stdc++.h>
using namespace std;
int te, tcnt, n, m, ret;
string a[54];
string s;

vector<string> v = {
"0001101",
"0011001",
"0010011",
"0111101",
"0100011",
"0110001",
"0101111",
"0111011",
"0110111",
"0001011"};

int main(){
	cin >> te;
	while(te--){
		tcnt++;
		
		cin >> n >> m;
		for(int i = 0; i < n; i++){
			cin >> a[i];
		}
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				if(a[i][j] == '1'){
					s = a[i];
					break;
				}
			}
		}
		int pos = 0;
		for(int i = m - 1; i >= 0; i--){
			if(s[i] == '1'){
				pos = i;
				break;
			}
		}
		s = s.substr(pos - 55, 56);
		int j = 1, k = 0, q = 0;
		for(int i = 0; i < 56; i += 7){
			int p = find(v.begin(), v.end(), s.substr(i, 7)) - v.begin();
			if(j % 2 == 1){
				k += 3 * p;
				q += p;
			}else{
				k += p;
				q += p;
			}
			j++;
		}
		if(k % 10 == 0) cout << "#" << tcnt << " " << q << "\n";
		else cout << "#" << tcnt << " " << 0 << "\n";
	}
}