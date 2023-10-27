#include<bits/stdc++.h>
using namespace std;
int n, num;

int main(){
	for(int te = 1; te <= 10; te++){
		deque<int> dq;
		cin >> n;
		for(int i = 0; i < 8; i++){
			cin >> num;
			dq.push_front(num);
		}
		int flag = 1;
		while(flag){
			for(int i = 1; i <= 5; i++){
				if(dq.back() - i <= 0){
					dq.pop_back();
					dq.push_front(0);
					flag = 0;
					break;
				}else{
					int temp = dq.back();
					dq.pop_back();
					dq.push_front(temp - i);
				}
			}
		}
		cout << "#" << te << " ";
		for(int i = dq.size() - 1; i >= 0; i--){
			cout << dq[i] << " ";
		}
		cout << "\n";
	}
}