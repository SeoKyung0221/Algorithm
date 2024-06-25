#include<bits/stdc++.h>
using namespace std;
int n, ret = -1e9;
string s;
vector<int> num;
vector<char> oper_str;

int oper(char a, int b, int c){
	if(a == '+') return b + c;
	if(a == '-') return b - c;
	if(a == '*') return b * c;
}

void go(int idx, int _num){
	if(idx == num.size() - 1){
		ret = max(ret, _num);
		return;
	}
	go(idx + 1, oper(oper_str[idx], _num, num[idx + 1]));
	
	if(idx + 2 <= num.size() - 1){
		int temp = oper(oper_str[idx + 1], num[idx + 1], num[idx + 2]);
		
		go(idx + 2, oper(oper_str[idx], _num, temp));
	}
	return;
}
int main(){
	cin >> n >> s;
	
	for(int i = 0; i < s.size(); i++){
		if(s[i] >= '0' && s[i] <= '9') num.push_back(s[i] - '0');
		else oper_str.push_back(s[i]);
	}
	go(0, num[0]);
	
	cout << ret << "\n";
}