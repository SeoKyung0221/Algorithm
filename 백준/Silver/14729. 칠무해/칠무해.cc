#include<bits/stdc++.h>
using namespace std;
int n;
map<double, int> mp;
double num;

int main(){
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> num;
		mp[num]++;
	}
	int cnt = 0;
	for(auto it = mp.begin(); it != mp.end(); it++){
		for(int i = 0; i < (*it).second; i++){
			if(cnt == 7) break;
			printf("%.3lf\n", (*it).first);
			cnt++;
		}
	}
}