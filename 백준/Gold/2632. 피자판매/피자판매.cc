#include<bits/stdc++.h>
using namespace std;
int want, m, n, a[1004], b[1004], a_psum[2008], b_psum[2008], ret;
map<int, int> aCnt, bCnt;

void makePizza(int k, map<int, int> &mp, int psum[]){
	for(int size = 1; size <= k; size++){
		for(int start = 1; start <= k; start++){
			int sum = psum[start + size - 1] - psum[start - 1];
			mp[sum]++;
			if(size == k) break;
		}
	}
}
int main(){
	cin >> want >> m >> n;
	for(int i = 1; i <= m; i++){
		cin >> a[i];
		a_psum[i] = a_psum[i - 1] + a[i];
	}
	for(int i = m + 1; i <= 2 * m; i++){
		a_psum[i] = a_psum[i - 1] + a[i - m];
	}
	for(int i = 1; i <= n; i++){
		cin >> b[i];
		b_psum[i] = b_psum[i - 1] + b[i];
	}
	for(int i = n + 1; i <= 2 * n; i++){
		b_psum[i] = b_psum[i - 1] + b[i - n];
	}
	makePizza(m, aCnt, a_psum);
	makePizza(n, bCnt, b_psum);
	
	ret = aCnt[want] + bCnt[want];
	for(int i = 1; i < want; i++){
		ret += (aCnt[i] * bCnt[want - i]);
	}
	cout << ret << "\n";
}