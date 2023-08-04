#include<bits/stdc++.h>
using namespace std;
int n, t;
string s;

int main(){
	cin >> n;
	int cnt1 = 0, cnt2 = 0, ret1 = 0, ret2 = 0, prev = 0;

	for(int i = 0; i < n; i++){
		cin >> t >> s;
		int hour = atoi((s.substr(0,2)).c_str());
		int min = atoi((s.substr(3, 2)).c_str());
		int time = 60 * hour + min;
		if(cnt1 > cnt2){
			ret1 += time - prev;
		}else if(cnt1 < cnt2){
			ret2 += time - prev;
		}
		prev = time;
		if(t == 1) cnt1++;
		else cnt2++;
	}
	if(cnt1 > cnt2){
		ret1 += 48 * 60 - prev;
	}else if(cnt1 < cnt2){
		ret2 += 48 * 60 - prev;
	}
	printf("%02d:%02d\n", ret1 / 60, ret1 % 60);
	printf("%02d:%02d\n", ret2 / 60, ret2 % 60);
	return 0;
}