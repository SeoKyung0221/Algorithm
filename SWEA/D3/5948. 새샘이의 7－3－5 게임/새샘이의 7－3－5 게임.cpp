#include<bits/stdc++.h>
using namespace std;
int te, tcnt, a[8];
vector<int> v;

void combi(int start, vector<int> &b){
	if(b.size() == 3){
		int num = 0;
		for(int i : b){
			num += a[i];
		}
		v.push_back(num);
		return;
	}
	for(int i = start + 1; i < 7; i++){
		b.push_back(i);
		combi(i, b);
		b.pop_back();
	}
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
	cin >> te;
	while(te--){
		tcnt++;
		v.clear();
		
		for(int i = 0; i < 7; i++){
			cin >> a[i];
		}
		vector<int> b;
		combi(-1, b);
		sort(v.begin(), v.end());
		v.erase(unique(v.begin(), v.end()), v.end());
		
		cout << "#" << tcnt << " " << v[v.size() - 5] << "\n"; 
	}
}