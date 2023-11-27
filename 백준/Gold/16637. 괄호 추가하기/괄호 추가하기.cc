#include<bits/stdc++.h>
using namespace std;
int n, ret = -1e9;
string s;
vector<char> oper_;
vector<int> num_;

int oper(int a, int b, char c){
	if(c == '+') return a + b;
	if(c == '-') return a - b;
	if(c == '*') return a * b;
}
void go(int idx, int num){
	if(idx == num_.size() - 1){
		ret = max(ret, num);
		return;
	}
	go(idx + 1, oper(num, num_[idx + 1], oper_[idx]));
	
	if(idx + 2 <= num_.size() - 1){
		int temp = oper(num_[idx + 1], num_[idx + 2], oper_[idx+1]);
		go(idx + 2, oper(num, temp, oper_[idx]));
	}
	return;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> s;
	for(int i = 0; i < n; i++){
		if(i % 2 == 0) num_.push_back(s[i] - '0');
		else oper_.push_back(s[i]);
	}
	go(0, num_[0]);
	cout << ret << '\n';
}