#include<bits/stdc++.h>
using namespace std;
string s;

int main(){
	while(true){
		cin >> s;
		if(s == "end") break;
		
		int flag = 0;
		int moflag = 0, jaflag = 0;
		int bad = 0;
		char prev = s[0];
		if(s[0] == 'a' || s[0] == 'e' || s[0] == 'i' || s[0] == 'o' || s[0] == 'u'){
			flag = 1;
			jaflag = 0;
			moflag++;
		}else{
			moflag = 0;
			jaflag++;
		}
	 	for(int i = 1; i < s.size(); i++){
			if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u'){
				flag = 1;
				jaflag = 0;
				moflag++;
			}else{
				moflag = 0;
				jaflag++;
			}
			if(moflag == 3 || jaflag == 3){
				bad = 1;
				break;
			}
			if(prev == s[i]){
				if(s[i] == 'e' || s[i] == 'o') continue;
				else{
					bad = 1;
					break;
				}
			}
			prev = s[i];
		}
		if(bad == 1 || flag == 0) cout << "<" << s << "> is not acceptable.\n";
		else cout << "<" << s << "> is acceptable.\n"; 
	}
}