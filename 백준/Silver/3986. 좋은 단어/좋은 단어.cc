#include<bits/stdc++.h>
using namespace std;
int n, ret;
string str;

int main(){
	cin >> n;
	
	for(int i = 0; i < n; i++){
		cin >> str;
		stack<char> stk;
		for(char a : str){
			if(stk.size() && stk.top() == a)
				stk.pop();
			else
				stk.push(a);
		}
		if(stk.size() == 0)
			ret++;
	}
	cout << ret << "\n";
}