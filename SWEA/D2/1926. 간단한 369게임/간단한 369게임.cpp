#include<bits/stdc++.h>
using namespace std;
int n;

int main(){
	cin >> n;
	for(int i = 1; i <= n; i++){
		string s = to_string(i);
		int flag = 0;
		for(char a : s){
			if(a == '3' || a == '6' || a == '9'){
				cout << "-";
				flag = 1;
			}
		}
		if(flag == 0) cout << s << " ";
		else cout << " ";
	}
}