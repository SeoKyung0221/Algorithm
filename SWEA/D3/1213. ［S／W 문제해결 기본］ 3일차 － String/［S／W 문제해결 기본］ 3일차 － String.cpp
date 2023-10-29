#include<bits/stdc++.h>
using namespace std;
int n, ret;
string s1, s2;

int main(){
	for(int te = 1; te <= 10; te++){
		ret = 0;
		cin >> n;
		cin >> s1 >> s2;
		int pos = 0;
		while((pos = s2.find(s1)) != string::npos){
			ret++;
			s2.erase(0, pos + s1.size());
		}
		cout << "#" << te << " " << ret << "\n";
	}
}