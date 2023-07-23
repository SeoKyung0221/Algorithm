#include<bits/stdc++.h>
using namespace std;
string s;
int ret = 987654321;

int main(){
	cin >> s;
	int flag = 0;
	for(int i = 1; i <= atoi(s.c_str()) * 10; i++){
		string k = to_string(i);
		int cnt = i;
		for(int j = 0; j < k.size(); j++){
			cnt += k[j] - '0';
		}
		if(cnt == atoi(s.c_str())){
			flag = 1;
			ret = min(ret, i);
		}
	}
	if(flag) cout << ret << "\n";
	else cout << "0\n";
}