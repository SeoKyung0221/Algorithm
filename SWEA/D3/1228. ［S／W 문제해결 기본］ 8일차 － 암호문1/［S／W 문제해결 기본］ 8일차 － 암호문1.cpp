#include<bits/stdc++.h>
using namespace std;
int n, x, y;
char trash;
string s, a[35];
int main(){
	for(int te = 1; te <= 10; te++){
		fill(a, a + 35, "");
		cin >> n;
		for(int i = 0; i < n; i++){
			cin >> a[i];
		}
		cin >> n;
		for(int i = 0; i < n; i++){
			cin >> trash >> x >> y;
			for(int j = 9; j >= x; j--){
				string temp = a[j];
				if(j + y < 10) a[j + y] = temp; 
			}
			for(int j = x; j < x + y; j++){
				cin >> s;
				if(j < 10) a[j] = s;
			}
		}
		cout << "#" << te << " ";
		for(int i = 0; i < 10; i++){
			cout << a[i] << " ";
		}
		cout << "\n";
	}
}