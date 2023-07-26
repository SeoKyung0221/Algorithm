#include<bits/stdc++.h>
using namespace std;
int n, m, ret;
string s;
vector<string> v;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	
	for(int i = 0; i < n; i++){
		cin >> s;
		v.push_back(s);
	}
	sort(v.begin(), v.end());
	for(int i = 0; i < m; i++){
		cin >> s;
		int l = 0, h = n - 1;
		while(l <= h){
			int mid = (l+h) / 2;
			if(v[mid] < s) l = mid + 1;
			else if(v[mid] > s) h = mid - 1;
			else{
				ret++;
				break;
			}
		}
	}
	cout << ret << "\n";
}