#include<bits/stdc++.h>
using namespace std;
int n;
string s;

int main(){
	for(int te = 1; te <= 10; te++){
		cin >> n >> s;
		stack<char> stk;
		
		for(char a : s){
			if(stk.size() && stk.top() == a){
				stk.pop();
			}else{
				stk.push(a);
			}
		}
		string ret = "";
		while(stk.size()){
			ret = stk.top() + ret;
			stk.pop();
		}
		cout << "#" << te << " " << ret << "\n";
	}
}