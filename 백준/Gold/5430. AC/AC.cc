#include<bits/stdc++.h>
using namespace std;
int te, n;
string p, q;

int main(){
	cin >> te;
	while(te--){
		cin >> p >> n >> q;
		deque<int> dq;
		int x = 0;
		for(char a : q){
			if(a == '[' || a == ']') continue;
			else if(a >= '0' && a <= '9') x = x * 10 + a - '0';
			else{
				if(x > 0) dq.push_back(x);
				x = 0;
			}
		}
		if(x > 0) dq.push_back(x);
		
		int rFlag = 0;
		int flag = 0;
		
		for(char a : p){
			if(a == 'R') rFlag = !rFlag;
			else{
				if(dq.empty()){
					flag = 1;
					break;
				}
				if(rFlag){
					dq.pop_back();
				}else{
					dq.pop_front();
				}
			}
		}
		if(flag) cout << "error\n";
		else{
			if(rFlag) reverse(dq.begin(), dq.end());
			cout << "[";
			for(int i = 0; i < dq.size(); i++){
				cout << dq[i];
				if(i < dq.size() - 1){
					cout << ",";
				}
			}
			cout << "]\n";
		}
	}
}