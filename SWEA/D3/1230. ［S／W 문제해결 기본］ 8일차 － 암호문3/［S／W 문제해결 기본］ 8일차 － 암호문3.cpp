#include<bits/stdc++.h>
using namespace std;
int n, m, x, y;
string a[4004], s;
char command;

int main(){
	for(int te = 1; te <= 10; te++){
		cin >> n;
		for(int i = 0; i < n; i++){
			cin >> a[i];
		}
		cin >> m;
		for(int i = 0; i < m; i++){
			cin >> command;
			if(command == 'I'){
				cin >> x >> y;
				for(int j = n - y; j >= x; j--){
					string temp = a[j];
					a[j + y] = temp; 
				}
				for(int j = x; j < x + y; j++){
					cin >> s;
					a[j] = s;
				}
			}else if(command == 'D'){
				cin >> x >> y;
				for(int j = x; j < x + y; j++){
					a[j] = a[j + y];
				}
			}else{
				cin >> y;
				for(int j = n; j < n + y; j++){
					cin >> s;
					if(j < 4004) a[j] = s;
				}
			}
		}
		cout << "#" << te << " ";
		for(int i = 0; i < 10; i++){
			cout << a[i] << " ";
		}
		cout << "\n";
	}
}