#include<bits/stdc++.h>
using namespace std;
int che[1000004];
vector<int> v;

void era(int n){
	for(int i = 2; i <= n; i++){
		if(che[i]) continue;
		for(int j = 2 * i; j <= n; j+=i){
			che[j] = 1;
		}
	}
	for(int i = 2; i <= n; i++){
		if(che[i] == 0) v.push_back(i);
	}
}
int main(){
	era(1000000);
	for(int i : v){
		cout << i << " ";
	}
}