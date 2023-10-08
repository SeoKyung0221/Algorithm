#include<bits/stdc++.h>
using namespace std;
int n, visited[10];
char a[14];
vector<string> ret;

bool good(char a, char op, int i){
	if(op == '<' && (a-'0') < i) return true;
	if(op == '>' && (a-'0') > i) return true;
	return false;
}
void go(int idx, string num){
	if(idx == n+1){
		ret.push_back(num);
		return;
	}
	for(int i = 0; i <= 9; i++){
		if(visited[i]) continue;
		if(idx == 0 || good(num[num.size()-1], a[idx-1], i)){
			visited[i] = 1;
			go(idx + 1, num + to_string(i));
			visited[i] = 0;
		}
	}
}
int main(){
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	go(0, "");
	sort(ret.begin(), ret.end());
	cout << ret[ret.size() - 1] << "\n" << ret[0] << "\n";
	return 0;
}