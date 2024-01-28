#include<bits/stdc++.h>
using namespace std;
int m, x, s;
string str;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> m;
	for(int i = 0; i < m; i++){
		cin >> str;
		if(str == "add"){
			cin >> x;
			s |= (1 << (x-1));
		} else if(str == "remove"){
			cin >> x;
			s &= ~(1 << (x-1));
		} else if(str == "check"){
			cin >> x;			
			if(s & (1 << (x-1)))
				cout << 1 << "\n";
			else
				cout << 0 << "\n";
		} else if(str == "toggle"){
			cin >> x;
			s ^= (1 << (x-1));
		} else if(str == "all"){
			s = (1 << 20) - 1;
		} else
			s = 0;
	}
	return 0;
}