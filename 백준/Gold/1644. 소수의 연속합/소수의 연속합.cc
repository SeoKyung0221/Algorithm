#include<bits/stdc++.h>
using namespace std;
int n, che[4000004], ret;
vector<int> v;

void era(int n){
	for(int i = 2; i <= n; i++){
		if(che[i]) continue;
		for(int j = 2 * i; j <= n; j += i){
			che[j] = 1;
		}
	}
	for(int i = 2; i <= n; i++){
		if(che[i] != 1) v.push_back(i);
	}
}
int main(){
	cin >> n;
	
	era(n);
	
	int l = 0, h = 0, temp = 0;
	while(true){
		if(temp >= n) temp -= v[l++];
		else if(h == v.size()) break;
		else temp += v[h++];
		if(temp == n) ret++;
	}
	cout << ret << "\n";
}