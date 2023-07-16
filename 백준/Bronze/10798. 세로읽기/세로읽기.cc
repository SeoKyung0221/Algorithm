#include<bits/stdc++.h>
using namespace std;
string s;
char a[5][15];

int main(){
	for(int i = 0; i < 5; i++){
		cin >> s;
		for(int j = 0; j < s.size(); j++){
			a[i][j] = s[j];
		}
	}
	
	for(int i = 0; i < 15; i++){
		for(int j = 0; j < 5; j++){
			if(a[j][i] != NULL){
				cout << a[j][i];
			}
		}
	}
}