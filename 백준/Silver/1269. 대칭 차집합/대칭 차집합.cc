#include<bits/stdc++.h>
using namespace std;
int a, b, n, m, cnt, ret;
vector<int> c, d;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> a >> b;
	for(int i = 0; i < a; i++){
		cin >> n;
		c.push_back(n);
	}
	for(int i = 0; i < b; i++){
		cin >> m;
		d.push_back(m);
	}
	sort(c.begin(), c.end());
	sort(d.begin(), d.end());	
	for(int i = 0; i < a; i++){
		int l = 0, h = b-1;
		int mid;
		while(l <= h){
			mid = (l+h)/2;
			if(c[i] < d[mid]){
				h = mid - 1;
			} else if(c[i] == d[mid]){
				cnt++;
				break;
			} else{
				l = mid+1;
			}
		}
	}
	ret = (a+b) - 2*cnt;
	cout << ret << "\n";
}