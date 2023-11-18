#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, c, num;
vector<int> v;
map<int, int> mp;
map<int, int> mp_first;

bool cmp(int a, int b) {
	if (mp[a] == mp[b]) {
		return mp_first[a] < mp_first[b];
	}
	else return mp[a] > mp[b];
}
int main() {
	cin >> n >> c;
	for (int i = 0; i < n; i++) {
		cin >> num;
		mp[num]++;
		v.push_back(num);
		if (mp_first[num] == 0) mp_first[num] = i + 1;
	}
	sort(v.begin(), v.end(), cmp);

	for (int i : v) {
		cout << i << " ";
	}
}