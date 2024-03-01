#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll want, m, n, a[1004], b[1004], a_psum[2008], b_psum[2008], ret;
map<ll, ll> aCnt, bCnt;

void make(ll n, ll psum[], map<ll, ll> & mp){ 
    for(int interval = 1; interval <= n; interval++){
        for(int start = interval; start <= n + interval - 1; start++){
            ll sum = psum[start] - psum[start - interval];
            mp[sum]++;   
            if(interval == n) break;
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
	make(m, a_psum, aCnt); 
    make(n, b_psum, bCnt); 
	
	ret = aCnt[want] + bCnt[want];
	
	for(int i = 1; i < want; i++){
		ret += (aCnt[i] * bCnt[want - i]);
	}
	cout << ret << "\n";
}