#include<bits/stdc++.h>
using namespace std;
int t, c;

int main(){
	cin >> t;
	while(t--){
		cin >> c;
		cout << c / 25 << " ";
		c %= 25;
		
		cout << c / 10 << " ";
		c %= 10;
		
		cout << c / 5 << " ";
		c %= 5;
		
		cout << c / 1 << " \n";
	}
}