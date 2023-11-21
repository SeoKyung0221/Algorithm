#include<bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	while(true){
		string s;
		getline(cin, s);
		stack<char> stk;
		bool check = true;
		if(s==".") break;
		for(int i = 0; i < s.size(); i++){
			if(s[i] == '(' || s[i] == '[')
				stk.push(s[i]);
			if(s[i] == ')'){
				if(!stk.empty()){
					if(stk.top()=='(')
						stk.pop();
					else {
					check = false;
					break;
					}
				}
				else {
				check = false;
				break;
				}
			}
			if(s[i] == ']'){
				if(!stk.empty()){
					if(stk.top() == '[')
						stk.pop();
					else {
					check = false;
					break;
					}
				}
				else {
				check = false;
				break;
				}
			}
		}
		if(!stk.empty())
		check = false;
		if(check == true)
			cout << "yes\n";
		else if(check == false)
			cout << "no\n";
	}
	return 0;
}