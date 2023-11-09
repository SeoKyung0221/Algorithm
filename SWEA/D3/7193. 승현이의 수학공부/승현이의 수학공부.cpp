#include<bits/stdc++.h>
using namespace std;
int te, tcnt, n, ret;
string s;

int main(){
	cin >> te;
	while(te--){
		tcnt++;
		ret = 0;
		
		cin >> n >> s;
		if(n == 0){
			cout << "#" << tcnt << " " << 0 << "\n";
			continue;
		}
		for(int i = 0; i < s.size(); i++){
        	int k = s[i] - '0';
            ret = ((ret % (n-1)) + (k % (n-1))) % (n-1);
        }
		cout << "#" << tcnt << " " << ret << "\n";
	}
}