#include<bits/stdc++.h>
using namespace std;
int n;
string s;

int main(){
	cin >> n;
	for(int i = 0; i < n; i++){
		stack<char> stk;
		cin >> s;
		for(char a : s){
			if(a == '(') stk.push(a);
			else{
				if(stk.size() && stk.top() == '(') stk.pop();
				else stk.push(a);
			}
		}
		if(stk.size()) cout << "NO\n";
		else cout << "YES\n";
	}
}