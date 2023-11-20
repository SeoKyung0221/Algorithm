#include<bits/stdc++.h>
using namespace std;
int n, shoot, team1, team2, _prev, a, b;
string s;

int main(){
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> shoot >> s;
		int hour = stoi(s.substr(0, 2));
		int min = stoi(s.substr(3, 2));
		int _time = hour * 60 + min;
		if(team1 > team2){
			a += _time - _prev;
		}else if(team2 > team1){
			b += _time - _prev;
		}
		_prev = _time;
		if(shoot == 1) team1++;
		else team2++;
	}
	if(team1 > team2){
		a += 48 * 60 - _prev;
	}else if(team2 > team1){
		b += 48 * 60 - _prev;
	}
	printf("%02d:%02d\n", a / 60, a % 60);
	printf("%02d:%02d\n", b / 60, b % 60);
}
	
