#include<bits/stdc++.h>
using namespace std;
int n, a;
string s;

struct A{
	int age;
	int join;
	string name;
};

bool cmp(A a, A b){
	if(a.age == b.age) return a.join < b.join;
	else return a.age < b.age;
}
int main(){
	cin >> n;
	vector<A> v(n);
	for(int i = 0; i < n; i++){
		cin >> v[i].age >> v[i].name;
		v[i].join = i;
	}
	sort(v.begin(), v.end(), cmp);
	for(A i : v){
		cout << i.age << " " << i.name << "\n";
	}
}