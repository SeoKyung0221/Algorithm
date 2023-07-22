#include<bits/stdc++.h>
using namespace std;
int a, b, c;
int main(){
	while(true){
		cin >> a >> b >> c;
		int mx = 0;
		mx = max(mx, a);
		mx = max(mx, b);
		mx = max(mx, c);
		if(a == 0 && b == 0 && c == 0) break;
		
		if(a == b && b == c && b == c){
			cout << "Equilateral\n";
			continue;
		}
		else{
			if(a == b || b == c || c == a){
				if(mx == a){
					if(a >= b+c){
						cout << "Invalid\n";
						continue;
					}
				}else if(mx == b){
					if(b >= a + c){
						cout << "Invalid\n";
						continue;
					}
				}else if(mx == c){
					if(c >= a + b){
						cout << "Invalid\n";
						continue;
					}
				}
				cout << "Isosceles\n";
				continue;
			}
			else if(a != b && b != c && c != a){
				if(mx == a){
					if(a >= b+c){
						cout << "Invalid\n";
						continue;
					}
				}else if(mx == b){
					if(b >= a + c){
						cout << "Invalid\n";
						continue;
					}
				}else if(mx == c){
					if(c >= a + b){
						cout << "Invalid\n";
						continue;
					}
				}
				cout << "Scalene\n";
				continue;				
			}
		}
	}
}